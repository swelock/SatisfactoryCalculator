#include "game_data.h"
#include "game_data_ext.h"
#include "complete_alternates.h"
#include <stdexcept>

GameData& GameData::instance()
{
    static GameData inst; // Initialized on first use
    return inst;
}

const QMap<QString, GameItem>& GameData::getItems() const
{
    return m_items;
}

GameData::GameData()
{
    loadData(); // Load all game data upon creation
}

const GameItem& GameData::getItem(const QString& className) const
{
    auto it = m_items.constFind(className);
    if (it == m_items.constEnd()) {
        throw std::runtime_error("Item not found: " + className.toStdString());
    }
    return it.value();
}

QList<GameRecipe> GameData::getRecipesForItem(const QString& className) const
{
    return m_recipesByItem.values(className);
}

bool GameData::hasRecipeForItem(const QString& className) const
{
    return m_recipesByItem.contains(className);
}

QString GameData::getItemName(const QString& className) const
{
    if (m_items.contains(className)) {
        return m_items.value(className).name;
    }
    return className; // Fallback
}

void GameData::addRecipe(const QString& forItem, const GameRecipe& recipe)
{
    m_recipesByItem.insert(forItem, recipe);
}

void GameData::addHubRequirement(int tier, const QVector<ItemAmount>& requirements)
{
    m_hubUpgradeRequirements.insert(tier, requirements);
}

void GameData::addElevatorRequirement(int phase, const QVector<ItemAmount>& requirements)
{
    m_liftPhaseRequirements.insert(phase, requirements);
}

void GameData::loadData()
{
    populateItems();
    populateRecipes();

    // Load complete alternate recipes (113 recipes)
    populateCompleteAlternateRecipes(*this);
    
    // Load HUB and Elevator requirements
    populateHubRequirements(*this);
    populateElevatorRequirements(*this);
}

void GameData::populateItems()
{
    // Raw Resources
    m_items.insert("Desc_IronOre_C", {"Железная руда", "Desc_IronOre_C", "Используется для создания железных слитков."});
    m_items.insert("Desc_CopperOre_C", {"Медная руда", "Desc_CopperOre_C", "Используется для создания медных слитков."});
    m_items.insert("Desc_Limestone_C", {"Известняк", "Desc_Limestone_C", "Используется для создания бетона."});
    m_items.insert("Desc_Coal_C", {"Уголь", "Desc_Coal_C", "Используется для энергетики и производства стали."});
    m_items.insert("Desc_CateriumOre_C", {"Катериевая руда", "Desc_CateriumOre_C", "Используется для создания катериевых слитков."});
    m_items.insert("Desc_RawQuartz_C", {"Сырой кварц", "Desc_RawQuartz_C", "Используется для создания кварцевых кристаллов."});
    m_items.insert("Desc_Sulfur_C", {"Сера", "Desc_Sulfur_C", "Используется в химических процессах."});
    m_items.insert("Desc_Bauxite_C", {"Боксит", "Desc_Bauxite_C", "Используется для производства алюминия."});
    m_items.insert("Desc_UraniumOre_C", {"Урановая руда", "Desc_UraniumOre_C", "Радиоактивная руда для ядерной энергетики."});
    m_items.insert("Desc_SAM_C", {"САМ руда", "Desc_SAM_C", "Загадочная руда для продвинутых технологий."});

    // Fluids
    m_items.insert("Desc_Water_C", {"Вода", "Desc_Water_C", "Необходима для многих процессов."});
    m_items.insert("Desc_LiquidOil_C", {"Нефть", "Desc_LiquidOil_C", "Сырая нефть для переработки."});
    m_items.insert("Desc_HeavyOilResidue_C", {"Тяжелые нефтяные остатки", "Desc_HeavyOilResidue_C", "Побочный продукт переработки нефти."});
    m_items.insert("Desc_Fuel_C", {"Топливо", "Desc_Fuel_C", "Переработанное топливо для энергетики."});
    m_items.insert("Desc_TurboFuel_C", {"Турботопливо", "Desc_TurboFuel_C", "Высокооктановое топливо."});

    // Ingots
    m_items.insert("Desc_IronIngot_C", {"Железный слиток", "Desc_IronIngot_C", "Основа большинства конструкций."});
    m_items.insert("Desc_CopperIngot_C", {"Медный слиток", "Desc_CopperIngot_C", "Используется в электротехнике."});
    m_items.insert("Desc_CateriumIngot_C", {"Катериевый слиток", "Desc_CateriumIngot_C", "Очень проводящий металл."});
    m_items.insert("Desc_SteelIngot_C", {"Стальной слиток", "Desc_SteelIngot_C", "Прочнее железа."});
    m_items.insert("Desc_AluminumIngot_C", {"Алюминиевый слиток", "Desc_AluminumIngot_C", "Легкий и прочный металл."});

    // Basic Parts
    m_items.insert("Desc_IronPlate_C", {"Железная пластина", "Desc_IronPlate_C", ""});
    m_items.insert("Desc_IronRod_C", {"Железный стержень", "Desc_IronRod_C", ""});
    m_items.insert("Desc_Screw_C", {"Винт", "Desc_Screw_C", "Маленький, но важный."});
    m_items.insert("Desc_Wire_C", {"Проволока", "Desc_Wire_C", ""});
    m_items.insert("Desc_Cable_C", {"Кабель", "Desc_Cable_C", ""});
    m_items.insert("Desc_Concrete_C", {"Бетон", "Desc_Concrete_C", "Строительный материал для фундаментов."});
    m_items.insert("Desc_SteelPipe_C", {"Стальная труба", "Desc_SteelPipe_C", ""});
    m_items.insert("Desc_SteelBeam_C", {"Стальная балка", "Desc_SteelBeam_C", ""});
    m_items.insert("Desc_Quickwire_C", {"Быстрая проволока", "Desc_Quickwire_C", ""});
    m_items.insert("Desc_CopperSheet_C", {"Медный лист", "Desc_CopperSheet_C", ""});
    m_items.insert("Desc_AlcladAluminumSheet_C", {"Алюминиевый лист", "Desc_AlcladAluminumSheet_C", ""});
    m_items.insert("Desc_AluminumCasing_C", {"Алюминиевый корпус", "Desc_AluminumCasing_C", ""});

    // Standard Parts
    m_items.insert("Desc_ReinforcedIronPlate_C", {"Усиленная железная пластина", "Desc_ReinforcedIronPlate_C", ""});
    m_items.insert("Desc_Stator_C", {"Статор", "Desc_Stator_C", ""});
    m_items.insert("Desc_Rotor_C", {"Ротор", "Desc_Rotor_C", ""});
    m_items.insert("Desc_ModularFrame_C", {"Модульный каркас", "Desc_ModularFrame_C", ""});
    m_items.insert("Desc_EncasedIndustrialBeam_C", {"Железобетонная балка", "Desc_EncasedIndustrialBeam_C", ""});
    m_items.insert("Desc_Motor_C", {"Мотор", "Desc_Motor_C", ""});

    // Industrial Parts
    m_items.insert("Desc_ModularFrameHeavy_C", {"Тяжелый модульный каркас", "Desc_ModularFrameHeavy_C", ""});
    m_items.insert("Desc_MotorLightweight_C", {"Турбомотор", "Desc_MotorLightweight_C", ""});
    m_items.insert("Desc_CoolingSystem_C", {"Система охлаждения", "Desc_CoolingSystem_C", ""});
    m_items.insert("Desc_FusedModularFrame_C", {"Составной модульный каркас", "Desc_FusedModularFrame_C", ""});

    // Electronic Parts
    m_items.insert("Desc_CircuitBoard_C", {"Микросхема", "Desc_CircuitBoard_C", ""});
    m_items.insert("Desc_Computer_C", {"Компьютер", "Desc_Computer_C", ""});
    m_items.insert("Desc_RadioControlUnit_C", {"Блок радиоуправления", "Desc_RadioControlUnit_C", ""});
    m_items.insert("Desc_Supercomputer_C", {"Суперкомпьютер", "Desc_Supercomputer_C", ""});

    // Chemical Parts
    m_items.insert("Desc_Plastic_C", {"Пластик", "Desc_Plastic_C", "Полимер."});
    m_items.insert("Desc_Rubber_C", {"Резина", "Desc_Rubber_C", "Прыгучая."});
    m_items.insert("Desc_Silica_C", {"Кремнезем", "Desc_Silica_C", ""});
    m_items.insert("Desc_PetroleumCoke_C", {"Нефтяной кокс", "Desc_PetroleumCoke_C", ""});
    m_items.insert("Desc_Polymer_C", {"Полимерная смола", "Desc_Polymer_C", ""});

    // Nuclear Parts  
    m_items.insert("Desc_ElectromagneticControlRod_C", {"Электромагнитный стержень управления", "Desc_ElectromagneticControlRod_C", ""});
    m_items.insert("Desc_NuclearPasta_C", {"Ядерная паста", "Desc_NuclearPasta_C", "Чрезвычайно плотный материал."});

    // Advanced Electronics
    m_items.insert("Desc_CrystalOscillator_C", {"Кварцевый генератор", "Desc_CrystalOscillator_C", ""});
    m_items.insert("Desc_AssemblyDirectorSystem_C", {"Система управления сборкой", "Desc_AssemblyDirectorSystem_C", ""});
    m_items.insert("Desc_MagneticFieldGenerator_C", {"Генератор магнитного поля", "Desc_MagneticFieldGenerator_C", ""});
    m_items.insert("Desc_ThermalPropulsionRocket_C", {"Тепловая реактивная установка", "Desc_ThermalPropulsionRocket_C", ""});

    // SAM Technology
    m_items.insert("Desc_SAMFluctuator_C", {"САМ флуктуатор", "Desc_SAMFluctuator_C", ""});
    m_items.insert("Desc_TimeCrystal_C", {"Временной кристалл", "Desc_TimeCrystal_C", ""});
    m_items.insert("Desc_FicsiteTrigon_C", {"Фикситовый тригон", "Desc_FicsiteTrigon_C", ""});
    m_items.insert("Desc_BiochemicalSculptor_C", {"Биохимический скульптор", "Desc_BiochemicalSculptor_C", ""});
    m_items.insert("Desc_AIExpansionServer_C", {"Сервер расширения ИИ", "Desc_AIExpansionServer_C", ""});
    m_items.insert("Desc_BallisticWarpDrive_C", {"Баллистический варп-двигатель", "Desc_BallisticWarpDrive_C", ""});
    m_items.insert("Desc_NeuralQuantumProcessor_C", {"Нейроквантовый процессор", "Desc_NeuralQuantumProcessor_C", ""});
    m_items.insert("Desc_SuperpositionOscillator_C", {"Генератор суперпозиции", "Desc_SuperpositionOscillator_C", ""});

    // Equipment/Tools  
    m_items.insert("Desc_GasFilter_C", {"Газовый фильтр", "Desc_GasFilter_C", ""});

    // Missing advanced items referenced in recipes
    m_items.insert("Desc_QuartzCrystal_C", {"Кварцевый кристалл", "Desc_QuartzCrystal_C", ""});
    m_items.insert("Desc_HighSpeedConnector_C", {"Высокоскоростной соединитель", "Desc_HighSpeedConnector_C", ""});
    m_items.insert("Desc_AutomatedWiring_C", {"Автоматизированная проводка", "Desc_AutomatedWiring_C", ""});
    m_items.insert("Desc_VersatileFramework_C", {"Универсальный каркас", "Desc_VersatileFramework_C", ""});
    m_items.insert("Desc_Battery_C", {"Аккумулятор", "Desc_Battery_C", ""});
    m_items.insert("Desc_ModularEngine_C", {"Модульный двигатель", "Desc_ModularEngine_C", ""});
    m_items.insert("Desc_HeatSink_C", {"Радиатор", "Desc_HeatSink_C", ""});
    m_items.insert("Desc_NitrogenGas_C", {"Азот", "Desc_NitrogenGas_C", ""});
    m_items.insert("Desc_Diamonds_C", {"Алмазы", "Desc_Diamonds_C", ""});
    m_items.insert("Desc_FicsiteIngot_C", {"Фикситовый слиток", "Desc_FicsiteIngot_C", ""});
    m_items.insert("Desc_AluminumScrap_C", {"Алюминиевый лом", "Desc_AluminumScrap_C", ""});
    m_items.insert("Desc_CopperPowder_C", {"Медный порошок", "Desc_CopperPowder_C", ""});
    m_items.insert("Desc_PressureConversionCube_C", {"Куб преобразования давления", "Desc_PressureConversionCube_C", ""});
    m_items.insert("Desc_SingletySingularity_C", {"Сингулярность", "Desc_SingletySingularity_C", ""});
    m_items.insert("Desc_DarkMatterCrystal_C", {"Кристалл темной материи", "Desc_DarkMatterCrystal_C", ""});
    m_items.insert("Desc_ExcitedPhotonicMatter_C", {"Возбужденная фотонная материя", "Desc_ExcitedPhotonicMatter_C", ""});

    // Common raw materials
    m_items.insert("Desc_Wood_C", {"Древесина", "Desc_Wood_C", ""});
    m_items.insert("Desc_Biomass_C", {"Биомасса", "Desc_Biomass_C", ""});
    m_items.insert("Desc_CompactedCoal_C", {"Прессованный уголь", "Desc_CompactedCoal_C", ""});
    m_items.insert("Desc_SulfuricAcid_C", {"Серная кислота", "Desc_SulfuricAcid_C", ""});
    m_items.insert("Desc_AluminaSolution_C", {"Раствор глинозема", "Desc_AluminaSolution_C", ""});

    // Missing items for alternate recipes
    m_items.insert("Desc_PetroleumCoke_C", {"Нефтяной кокс", "Desc_PetroleumCoke_C", ""});
    m_items.insert("Desc_Polymer_C", {"Полимер", "Desc_Polymer_C", ""});
    m_items.insert("Desc_TurboMotor_C", {"Турбомотор", "Desc_TurboMotor_C", ""});
    m_items.insert("Desc_Leaves_C", {"Листья", "Desc_Leaves_C", ""});
    m_items.insert("Desc_HogParts_C", {"Части кабана", "Desc_HogParts_C", ""});
    m_items.insert("Desc_SpitterParts_C", {"Части плевка", "Desc_SpitterParts_C", ""});
    m_items.insert("Desc_UraniumCell_C", {"Урановый топливный элемент", "Desc_UraniumCell_C", ""});

    // Space Elevator Parts
    m_items.insert("Desc_SpaceElevatorPart_1_C", {"Умная обшивка", "Desc_SpaceElevatorPart_1_C", "Часть для лифта Фазы 1."});
    m_items.insert("Desc_SpaceElevatorPart_2_C", {"Универсальный каркас", "Desc_SpaceElevatorPart_2_C", "Часть для лифта Фазы 2."});
    m_items.insert("Desc_SpaceElevatorPart_3_C", {"Автоматизированная проводка", "Desc_SpaceElevatorPart_3_C", "Часть для лифта Фазы 3."});
    m_items.insert("Desc_SpaceElevatorPart_4_C", {"Модульный двигатель", "Desc_SpaceElevatorPart_4_C", "Часть для лифта Фазы 4."});
    m_items.insert("Desc_AdaptiveControlUnit_C", {"Адаптивный блок управления", "Desc_AdaptiveControlUnit_C", ""});
}

void GameData::populateRecipes()
{
    GameRecipe recipe;

    // --- INGOTS ---
    recipe = {"Железный слиток", "Recipe_IronIngot_C", 2.0, {{"Desc_IronOre_C", 1}}, {{"Desc_IronIngot_C", 1}}, "Плавильня"};
    m_recipesByItem.insert("Desc_IronIngot_C", recipe);

    recipe = {"Медный слиток", "Recipe_CopperIngot_C", 2.0, {{"Desc_CopperOre_C", 1}}, {{"Desc_CopperIngot_C", 1}}, "Плавильня"};
    m_recipesByItem.insert("Desc_CopperIngot_C", recipe);

    recipe = {"Катериевый слиток", "Recipe_CateriumIngot_C", 4.0, {{"Desc_CateriumOre_C", 3}}, {{"Desc_CateriumIngot_C", 1}}, "Плавильня"};
    m_recipesByItem.insert("Desc_CateriumIngot_C", recipe);

    recipe = {"Стальной слиток", "Recipe_SteelIngot_C", 4.0, {{"Desc_IronOre_C", 3}, {"Desc_Coal_C", 3}}, {{"Desc_SteelIngot_C", 3}}, "Литейная"};
    m_recipesByItem.insert("Desc_SteelIngot_C", recipe);

    recipe = {"Алюминиевый слиток", "Recipe_AluminumIngot_C", 4.0, {{"Desc_AluminumScrap_C", 6}, {"Desc_Silica_C", 5}}, {{"Desc_AluminumIngot_C", 4}}, "Литейная"};
    m_recipesByItem.insert("Desc_AluminumIngot_C", recipe);

    // --- BASIC PARTS ---
    recipe = {"Железная пластина", "Recipe_IronPlate_C", 6.0, {{"Desc_IronIngot_C", 3}}, {{"Desc_IronPlate_C", 2}}, "Конструктор"};
    m_recipesByItem.insert("Desc_IronPlate_C", recipe);

    recipe = {"Железный стержень", "Recipe_IronRod_C", 4.0, {{"Desc_IronIngot_C", 1}}, {{"Desc_IronRod_C", 1}}, "Конструктор"};
    m_recipesByItem.insert("Desc_IronRod_C", recipe);

    recipe = {"Винт", "Recipe_Screw_C", 6.0, {{"Desc_IronRod_C", 1}}, {{"Desc_Screw_C", 4}}, "Конструктор"};
    m_recipesByItem.insert("Desc_Screw_C", recipe);

    recipe = {"Проволока", "Recipe_Wire_C", 4.0, {{"Desc_CopperIngot_C", 1}}, {{"Desc_Wire_C", 2}}, "Конструктор"};
    m_recipesByItem.insert("Desc_Wire_C", recipe);

    recipe = {"Кабель", "Recipe_Cable_C", 4.0, {{"Desc_Wire_C", 2}}, {{"Desc_Cable_C", 1}}, "Конструктор"};
    m_recipesByItem.insert("Desc_Cable_C", recipe);

    recipe = {"Бетон", "Recipe_Concrete_C", 4.0, {{"Desc_Limestone_C", 3}}, {{"Desc_Concrete_C", 1}}, "Конструктор"};
    m_recipesByItem.insert("Desc_Concrete_C", recipe);

    recipe = {"Стальная труба", "Recipe_SteelPipe_C", 6.0, {{"Desc_SteelIngot_C", 3}}, {{"Desc_SteelPipe_C", 2}}, "Конструктор"};
    m_recipesByItem.insert("Desc_SteelPipe_C", recipe);

    recipe = {"Стальная балка", "Recipe_SteelBeam_C", 4.0, {{"Desc_SteelIngot_C", 4}}, {{"Desc_SteelBeam_C", 1}}, "Конструктор"};
    m_recipesByItem.insert("Desc_SteelBeam_C", recipe);

    recipe = {"Быстрая проволока", "Recipe_Quickwire_C", 5.0, {{"Desc_CateriumIngot_C", 1}}, {{"Desc_Quickwire_C", 5}}, "Конструктор"};
    m_recipesByItem.insert("Desc_Quickwire_C", recipe);

    recipe = {"Медный лист", "Recipe_CopperSheet_C", 6.0, {{"Desc_CopperIngot_C", 2}}, {{"Desc_CopperSheet_C", 1}}, "Конструктор"};
    m_recipesByItem.insert("Desc_CopperSheet_C", recipe);

    recipe = {"Алюминиевый лист", "Recipe_AlcladAluminumSheet_C", 6.0, {{"Desc_AluminumIngot_C", 3}, {"Desc_CopperIngot_C", 1}}, {{"Desc_AlcladAluminumSheet_C", 3}}, "Сборщик"};
    m_recipesByItem.insert("Desc_AlcladAluminumSheet_C", recipe);

    recipe = {"Алюминиевый корпус", "Recipe_AluminumCasing_C", 2.0, {{"Desc_AluminumIngot_C", 3}}, {{"Desc_AluminumCasing_C", 2}}, "Конструктор"};
    m_recipesByItem.insert("Desc_AluminumCasing_C", recipe);

    // --- STANDARD PARTS ---
    recipe = {"Усиленная железная пластина", "Recipe_ReinforcedIronPlate_C", 12.0, {{"Desc_IronPlate_C", 6}, {"Desc_Screw_C", 12}}, {{"Desc_ReinforcedIronPlate_C", 1}}, "Сборщик"};
    m_recipesByItem.insert("Desc_ReinforcedIronPlate_C", recipe);

    recipe = {"Статор", "Recipe_Stator_C", 12.0, {{"Desc_SteelPipe_C", 3}, {"Desc_Wire_C", 8}}, {{"Desc_Stator_C", 1}}, "Сборщик"};
    m_recipesByItem.insert("Desc_Stator_C", recipe);

    recipe = {"Ротор", "Recipe_Rotor_C", 15.0, {{"Desc_IronRod_C", 5}, {"Desc_Screw_C", 25}}, {{"Desc_Rotor_C", 1}}, "Сборщик"};
    m_recipesByItem.insert("Desc_Rotor_C", recipe);

    recipe = {"Модульный каркас", "Recipe_ModularFrame_C", 60.0, {{"Desc_ReinforcedIronPlate_C", 3}, {"Desc_IronRod_C", 12}}, {{"Desc_ModularFrame_C", 2}}, "Сборщик"};
    m_recipesByItem.insert("Desc_ModularFrame_C", recipe);

    recipe = {"Железобетонная балка", "Recipe_EncasedIndustrialBeam_C", 10.0, {{"Desc_SteelBeam_C", 4}, {"Desc_Concrete_C", 5}}, {{"Desc_EncasedIndustrialBeam_C", 1}}, "Сборщик"};
    m_recipesByItem.insert("Desc_EncasedIndustrialBeam_C", recipe);

    recipe = {"Мотор", "Recipe_Motor_C", 12.0, {{"Desc_Rotor_C", 2}, {"Desc_Stator_C", 2}}, {{"Desc_Motor_C", 1}}, "Сборщик"};
    m_recipesByItem.insert("Desc_Motor_C", recipe);

    // --- INDUSTRIAL PARTS ---
    recipe = {"Тяжелый модульный каркас", "Recipe_ModularFrameHeavy_C", 30.0, {{"Desc_ModularFrame_C", 5}, {"Desc_SteelPipe_C", 15}, {"Desc_EncasedIndustrialBeam_C", 5}, {"Desc_Screw_C", 100}}, {{"Desc_ModularFrameHeavy_C", 1}}, "Производитель"};
    m_recipesByItem.insert("Desc_ModularFrameHeavy_C", recipe);

    recipe = {"Турбомотор", "Recipe_MotorLightweight_C", 32.0, {{"Desc_CoolingSystem_C", 4}, {"Desc_RadioControlUnit_C", 2}, {"Desc_Motor_C", 4}, {"Desc_Rubber_C", 24}}, {{"Desc_MotorLightweight_C", 1}}, "Производитель"};
    m_recipesByItem.insert("Desc_MotorLightweight_C", recipe);

    recipe = {"Система охлаждения", "Recipe_CoolingSystem_C", 8.0, {{"Desc_HeatSink_C", 2}, {"Desc_Rubber_C", 2}}, {{"Desc_CoolingSystem_C", 1}}, "Сборщик"};
    m_recipesByItem.insert("Desc_CoolingSystem_C", recipe);

    recipe = {"Составной модульный каркас", "Recipe_FusedModularFrame_C", 40.0, {{"Desc_ModularFrameHeavy_C", 1}, {"Desc_AluminumCasing_C", 50}}, {{"Desc_FusedModularFrame_C", 1}}, "Сборщик"};
    m_recipesByItem.insert("Desc_FusedModularFrame_C", recipe);

    // --- ELECTRONIC PARTS ---
    recipe = {"Микросхема", "Recipe_CircuitBoard_C", 8.0, {{"Desc_CopperSheet_C", 2}, {"Desc_Plastic_C", 4}}, {{"Desc_CircuitBoard_C", 1}}, "Сборщик"};
    m_recipesByItem.insert("Desc_CircuitBoard_C", recipe);

    recipe = {"Компьютер", "Recipe_Computer_C", 24.0, {{"Desc_CircuitBoard_C", 10}, {"Desc_Cable_C", 9}, {"Desc_Plastic_C", 18}, {"Desc_Screw_C", 52}}, {{"Desc_Computer_C", 1}}, "Производитель"};
    m_recipesByItem.insert("Desc_Computer_C", recipe);

    recipe = {"Блок радиоуправления", "Recipe_RadioControlUnit_C", 48.0, {{"Desc_AluminumCasing_C", 32}, {"Desc_CrystalOscillator_C", 1}, {"Desc_Computer_C", 1}}, {{"Desc_RadioControlUnit_C", 2}}, "Производитель"};
    m_recipesByItem.insert("Desc_RadioControlUnit_C", recipe);

    recipe = {"Суперкомпьютер", "Recipe_Supercomputer_C", 32.0, {{"Desc_Computer_C", 2}, {"Desc_HighSpeedConnector_C", 2}, {"Desc_Plastic_C", 28}, {"Desc_Quickwire_C", 62}}, {{"Desc_Supercomputer_C", 1}}, "Сборщик"};
    m_recipesByItem.insert("Desc_Supercomputer_C", recipe);

    // --- CHEMICAL PARTS ---
    recipe = {"Пластик", "Recipe_Plastic_C", 6.0, {{"Desc_LiquidOil_C", 3}}, {{"Desc_Plastic_C", 2}}, "Очиститель"};
    m_recipesByItem.insert("Desc_Plastic_C", recipe);

    recipe = {"Резина", "Recipe_Rubber_C", 6.0, {{"Desc_LiquidOil_C", 3}}, {{"Desc_Rubber_C", 2}}, "Очиститель"};
    m_recipesByItem.insert("Desc_Rubber_C", recipe);

    recipe = {"Кремнезем", "Recipe_Silica_C", 8.0, {{"Desc_RawQuartz_C", 3}}, {{"Desc_Silica_C", 5}}, "Конструктор"};
    m_recipesByItem.insert("Desc_Silica_C", recipe);

    // --- ADVANCED ELECTRONICS ---
    recipe = {"Кварцевый генератор", "Recipe_CrystalOscillator_C", 120.0, {{"Desc_QuartzCrystal_C", 36}, {"Desc_Cable_C", 28}, {"Desc_ReinforcedIronPlate_C", 5}}, {{"Desc_CrystalOscillator_C", 2}}, "Производитель"};
    m_recipesByItem.insert("Desc_CrystalOscillator_C", recipe);

    recipe = {"Система управления сборкой", "Recipe_AssemblyDirectorSystem_C", 80.0, {{"Desc_Supercomputer_C", 2}, {"Desc_Quickwire_C", 50}}, {{"Desc_AssemblyDirectorSystem_C", 1}}, "Сборщик"};
    m_recipesByItem.insert("Desc_AssemblyDirectorSystem_C", recipe);

    recipe = {"Генератор магнитного поля", "Recipe_MagneticFieldGenerator_C", 120.0, {{"Desc_VersatileFramework_C", 5}, {"Desc_ElectromagneticControlRod_C", 2}, {"Desc_Battery_C", 10}}, {{"Desc_MagneticFieldGenerator_C", 2}}, "Производитель"};
    m_recipesByItem.insert("Desc_MagneticFieldGenerator_C", recipe);

    recipe = {"Тепловая реактивная установка", "Recipe_ThermalPropulsionRocket_C", 120.0, {{"Desc_ModularEngine_C", 5}, {"Desc_TurboMotor_C", 2}, {"Desc_CoolingSystem_C", 6}, {"Desc_FusedModularFrame_C", 2}}, {{"Desc_ThermalPropulsionRocket_C", 2}}, "Производитель"};
    m_recipesByItem.insert("Desc_ThermalPropulsionRocket_C", recipe);

    // --- NUCLEAR PARTS ---
    recipe = {"Электромагнитный стержень управления", "Recipe_ElectromagneticControlRod_C", 30.0, {{"Desc_Stator_C", 3}, {"Desc_HighSpeedConnector_C", 2}}, {{"Desc_ElectromagneticControlRod_C", 2}}, "Сборщик"};
    m_recipesByItem.insert("Desc_ElectromagneticControlRod_C", recipe);

    recipe = {"Ядерная паста", "Recipe_NuclearPasta_C", 120.0, {{"Desc_CopperPowder_C", 200}, {"Desc_PressureConversionCube_C", 1}}, {{"Desc_NuclearPasta_C", 1}}, "Ускоритель частиц"};
    m_recipesByItem.insert("Desc_NuclearPasta_C", recipe);

    // --- SAM TECHNOLOGY ---
    recipe = {"САМ флуктуатор", "Recipe_SAMFluctuator_C", 6.0, {{"Desc_SAM_C", 6}, {"Desc_Wire_C", 5}, {"Desc_SteelPipe_C", 3}}, {{"Desc_SAMFluctuator_C", 1}}, "Конвертер"};
    m_recipesByItem.insert("Desc_SAMFluctuator_C", recipe);

    recipe = {"Временной кристалл", "Recipe_TimeCrystal_C", 120.0, {{"Desc_Diamonds_C", 2}, {"Desc_SAMFluctuator_C", 1}}, {{"Desc_TimeCrystal_C", 3}}, "Конвертер"};
    m_recipesByItem.insert("Desc_TimeCrystal_C", recipe);

    recipe = {"Фикситовый тригон", "Recipe_FicsiteTrigon_C", 60.0, {{"Desc_FicsiteIngot_C", 1}, {"Desc_SAMFluctuator_C", 1}}, {{"Desc_FicsiteTrigon_C", 3}}, "Конвертер"};
    m_recipesByItem.insert("Desc_FicsiteTrigon_C", recipe);

    recipe = {"Биохимический скульптор", "Recipe_BiochemicalSculptor_C", 600.0, {{"Desc_AssemblyDirectorSystem_C", 1}, {"Desc_FicsiteTrigon_C", 8}}, {{"Desc_BiochemicalSculptor_C", 1}}, "Производитель"};
    m_recipesByItem.insert("Desc_BiochemicalSculptor_C", recipe);

    recipe = {"Сервер расширения ИИ", "Recipe_AIExpansionServer_C", 240.0, {{"Desc_MagneticFieldGenerator_C", 1}, {"Desc_NeuralQuantumProcessor_C", 1}, {"Desc_Supercomputer_C", 1}, {"Desc_CoolingSystem_C", 2}}, {{"Desc_AIExpansionServer_C", 1}}, "Производитель"};
    m_recipesByItem.insert("Desc_AIExpansionServer_C", recipe);

    recipe = {"Баллистический варп-двигатель", "Recipe_BallisticWarpDrive_C", 300.0, {{"Desc_ThermalPropulsionRocket_C", 1}, {"Desc_SingletySingularity_C", 1}, {"Desc_SuperpositionOscillator_C", 5}, {"Desc_DarkMatterCrystal_C", 40}}, {{"Desc_BallisticWarpDrive_C", 1}}, "Производитель"};
    m_recipesByItem.insert("Desc_BallisticWarpDrive_C", recipe);

    recipe = {"Нейроквантовый процессор", "Recipe_NeuralQuantumProcessor_C", 240.0, {{"Desc_TimeCrystal_C", 15}, {"Desc_Supercomputer_C", 1}, {"Desc_FicsiteTrigon_C", 45}, {"Desc_ExcitedPhotonicMatter_C", 75}}, {{"Desc_NeuralQuantumProcessor_C", 3}}, "Квантовый кодер"};
    m_recipesByItem.insert("Desc_NeuralQuantumProcessor_C", recipe);

    recipe = {"Генератор суперпозиции", "Recipe_SuperpositionOscillator_C", 180.0, {{"Desc_DarkMatterCrystal_C", 6}, {"Desc_CrystalOscillator_C", 1}, {"Desc_AlcladAluminumSheet_C", 9}}, {{"Desc_SuperpositionOscillator_C", 1}}, "Квантовый кодер"};
    m_recipesByItem.insert("Desc_SuperpositionOscillator_C", recipe);

    // --- SPACE ELEVATOR PARTS ---
    recipe = {"Умная обшивка", "Recipe_SpaceElevatorPart_1_C", 30.0, {{"Desc_ReinforcedIronPlate_C", 1}, {"Desc_Rotor_C", 1}}, {{"Desc_SpaceElevatorPart_1_C", 1}}, "Сборщик"};
    m_recipesByItem.insert("Desc_SpaceElevatorPart_1_C", recipe);

    recipe = {"Универсальный каркас", "Recipe_SpaceElevatorPart_2_C", 24.0, {{"Desc_ModularFrame_C", 1}, {"Desc_SteelBeam_C", 12}}, {{"Desc_SpaceElevatorPart_2_C", 2}}, "Сборщик"};
    m_recipesByItem.insert("Desc_SpaceElevatorPart_2_C", recipe);

    recipe = {"Автоматизированная проводка", "Recipe_SpaceElevatorPart_3_C", 24.0, {{"Desc_Stator_C", 1}, {"Desc_Cable_C", 20}}, {{"Desc_SpaceElevatorPart_3_C", 1}}, "Сборщик"};
    m_recipesByItem.insert("Desc_SpaceElevatorPart_3_C", recipe);

    recipe = {"Модульный двигатель", "Recipe_SpaceElevatorPart_4_C", 60.0, {{"Desc_Motor_C", 2}, {"Desc_Rubber_C", 15}, {"Desc_SpaceElevatorPart_1_C", 2}}, {{"Desc_SpaceElevatorPart_4_C", 1}}, "Производитель"};
    m_recipesByItem.insert("Desc_SpaceElevatorPart_4_C", recipe);

    recipe = {"Адаптивный блок управления", "Recipe_AdaptiveControlUnit_C", 120.0, {{"Desc_AutomatedWiring_C", 15}, {"Desc_CircuitBoard_C", 10}, {"Desc_ModularFrameHeavy_C", 2}, {"Desc_Computer_C", 2}}, {{"Desc_AdaptiveControlUnit_C", 2}}, "Производитель"};
    m_recipesByItem.insert("Desc_AdaptiveControlUnit_C", recipe);

    // --- MISSING RECIPES FOR INTERMEDIATE ITEMS ---
    recipe = {"Кварцевый кристалл", "Recipe_QuartzCrystal_C", 8.0, {{"Desc_RawQuartz_C", 5}}, {{"Desc_QuartzCrystal_C", 3}}, "Конструктор"};
    m_recipesByItem.insert("Desc_QuartzCrystal_C", recipe);

    recipe = {"Высокоскоростной соединитель", "Recipe_HighSpeedConnector_C", 16.0, {{"Desc_Quickwire_C", 56}, {"Desc_Cable_C", 10}, {"Desc_CircuitBoard_C", 1}}, {{"Desc_HighSpeedConnector_C", 1}}, "Производитель"};
    m_recipesByItem.insert("Desc_HighSpeedConnector_C", recipe);

    recipe = {"Автоматизированная проводка", "Recipe_AutomatedWiring_C", 24.0, {{"Desc_Stator_C", 1}, {"Desc_Cable_C", 20}}, {{"Desc_AutomatedWiring_C", 1}}, "Сборщик"};
    m_recipesByItem.insert("Desc_AutomatedWiring_C", recipe);

    recipe = {"Универсальный каркас", "Recipe_VersatileFramework_C", 24.0, {{"Desc_ModularFrame_C", 1}, {"Desc_SteelBeam_C", 12}}, {{"Desc_VersatileFramework_C", 2}}, "Сборщик"};
    m_recipesByItem.insert("Desc_VersatileFramework_C", recipe);

    recipe = {"Аккумулятор", "Recipe_Battery_C", 3.0, {{"Desc_SulfuricAcid_C", 3}, {"Desc_AluminumCasing_C", 1}}, {{"Desc_Battery_C", 1}}, "Сборщик"};
    m_recipesByItem.insert("Desc_Battery_C", recipe);

    recipe = {"Модульный двигатель", "Recipe_ModularEngine_C", 60.0, {{"Desc_Motor_C", 2}, {"Desc_Rubber_C", 15}, {"Desc_SpaceElevatorPart_1_C", 2}}, {{"Desc_ModularEngine_C", 1}}, "Производитель"};
    m_recipesByItem.insert("Desc_ModularEngine_C", recipe);

    recipe = {"Радиатор", "Recipe_HeatSink_C", 8.0, {{"Desc_AlcladAluminumSheet_C", 5}, {"Desc_CopperSheet_C", 3}}, {{"Desc_HeatSink_C", 1}}, "Сборщик"};
    m_recipesByItem.insert("Desc_HeatSink_C", recipe);

    recipe = {"Алюминиевый лом", "Recipe_AluminumScrap_C", 1.0, {{"Desc_AluminaSolution_C", 4}, {"Desc_Coal_C", 2}}, {{"Desc_AluminumScrap_C", 6}}, "Очиститель"};
    m_recipesByItem.insert("Desc_AluminumScrap_C", recipe);

    recipe = {"Медный порошок", "Recipe_CopperPowder_C", 6.0, {{"Desc_CopperIngot_C", 30}}, {{"Desc_CopperPowder_C", 50}}, "Ускоритель частиц"};
    m_recipesByItem.insert("Desc_CopperPowder_C", recipe);

    recipe = {"Куб преобразования давления", "Recipe_PressureConversionCube_C", 60.0, {{"Desc_FusedModularFrame_C", 1}, {"Desc_RadioControlUnit_C", 2}}, {{"Desc_PressureConversionCube_C", 1}}, "Сборщик"};
    m_recipesByItem.insert("Desc_PressureConversionCube_C", recipe);

    // Raw material processing
    recipe = {"Биомасса", "Recipe_Biomass_C", 4.0, {{"Desc_Wood_C", 1}}, {{"Desc_Biomass_C", 20}}, "Конструктор"};
    m_recipesByItem.insert("Desc_Biomass_C", recipe);

    recipe = {"Прессованный уголь", "Recipe_CompactedCoal_C", 12.0, {{"Desc_Coal_C", 5}, {"Desc_Sulfur_C", 5}}, {{"Desc_CompactedCoal_C", 5}}, "Сборщик"};
    m_recipesByItem.insert("Desc_CompactedCoal_C", recipe);

    // Missing fluid recipes
    recipe = {"Серная кислота", "Recipe_SulfuricAcid_C", 6.0, {{"Desc_Sulfur_C", 5}}, {{"Desc_SulfuricAcid_C", 5}}, "Очиститель"};
    m_recipesByItem.insert("Desc_SulfuricAcid_C", recipe);

    recipe = {"Раствор глинозема", "Recipe_AluminaSolution_C", 6.0, {{"Desc_Bauxite_C", 12}}, {{"Desc_AluminaSolution_C", 12}}, "Очиститель"};
    m_recipesByItem.insert("Desc_AluminaSolution_C", recipe);
}

const QMap<int, QVector<ItemAmount>>& GameData::getHubUpgradeRequirements() const
{
    return m_hubUpgradeRequirements;
}

const QMap<int, QVector<ItemAmount>>& GameData::getElevatorPhaseRequirements() const
{
    return m_liftPhaseRequirements;
} 