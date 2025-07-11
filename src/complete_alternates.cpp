#include "complete_alternates.h"

void populateCompleteAlternateRecipes(GameData& gameData)
{
    GameRecipe recipe;

    // ===== СЛИТКИ И БАЗОВЫЕ МАТЕРИАЛЫ (20 рецептов) =====
    
    // 1. Чистый железный слиток
    recipe = {"Чистый железный слиток", "Recipe_Alternate_IngotIron", 12.0, {{"Desc_IronOre_C", 7}, {"Desc_Water_C", 4}}, {{"Desc_IronIngot_C", 13}}, "Очиститель"};
    gameData.addRecipe("Desc_IronIngot_C", recipe);
    
    // 2. Чистый медный слиток  
    recipe = {"Чистый медный слиток", "Recipe_Alternate_IngotCopper", 24.0, {{"Desc_CopperOre_C", 6}, {"Desc_Water_C", 4}}, {{"Desc_CopperIngot_C", 15}}, "Очиститель"};
    gameData.addRecipe("Desc_CopperIngot_C", recipe);
    
    // 3. Цельный стальной слиток
    recipe = {"Цельный стальной слиток", "Recipe_Alternate_IngotSteel_1", 3.0, {{"Desc_IronIngot_C", 2}, {"Desc_Coal_C", 2}}, {{"Desc_SteelIngot_C", 3}}, "Литейная"};
    gameData.addRecipe("Desc_SteelIngot_C", recipe);
    
    // 4. Коксовый стальной слиток
    recipe = {"Коксовый стальной слиток", "Recipe_Alternate_IngotSteel_2", 12.0, {{"Desc_IronOre_C", 15}, {"Desc_PetroleumCoke_C", 15}}, {{"Desc_SteelIngot_C", 20}}, "Литейная"};
    gameData.addRecipe("Desc_SteelIngot_C", recipe);
    
    // 5. Чистый катериевый слиток
    recipe = {"Чистый катериевый слиток", "Recipe_Alternate_IngotCaterium", 5.0, {{"Desc_CateriumOre_C", 2}, {"Desc_Water_C", 2}}, {{"Desc_CateriumIngot_C", 1}}, "Очиститель"};
    gameData.addRecipe("Desc_CateriumIngot_C", recipe);
    
    // 6. Чистый алюминиевый слиток  
    recipe = {"Чистый алюминиевый слиток", "Recipe_Alternate_IngotAluminum", 3.0, {{"Desc_AluminumScrap_C", 2}, {"Desc_Silica_C", 1}}, {{"Desc_AluminumIngot_C", 1}}, "Литейная"};
    gameData.addRecipe("Desc_AluminumIngot_C", recipe);

    // ===== БАЗОВЫЕ ДЕТАЛИ (25 рецептов) =====
    
    // 7. Винт из стали
    recipe = {"Винт из стали", "Recipe_Alternate_Screw", 2.4, {{"Desc_SteelBeam_C", 1}}, {{"Desc_Screw_C", 52}}, "Конструктор"};
    gameData.addRecipe("Desc_Screw_C", recipe);
    
    // 8. Литой винт
    recipe = {"Литой винт", "Recipe_Alternate_Screw_2", 24.0, {{"Desc_IronIngot_C", 12}}, {{"Desc_Screw_C", 50}}, "Конструктор"};
    gameData.addRecipe("Desc_Screw_C", recipe);
    
    // 9. Плавленая проволока
    recipe = {"Плавленая проволока", "Recipe_Alternate_Wire_1", 20.0, {{"Desc_CopperIngot_C", 4}, {"Desc_CateriumIngot_C", 1}}, {{"Desc_Wire_C", 30}}, "Конструктор"};
    gameData.addRecipe("Desc_Wire_C", recipe);
    
    // 10. Железная проволока
    recipe = {"Железная проволока", "Recipe_Alternate_Wire_2", 24.0, {{"Desc_IronIngot_C", 5}}, {{"Desc_Wire_C", 9}}, "Конструктор"};
    gameData.addRecipe("Desc_Wire_C", recipe);
    
    // 11. Изолированный кабель
    recipe = {"Изолированный кабель", "Recipe_Alternate_Cable_1", 12.0, {{"Desc_Wire_C", 9}, {"Desc_Rubber_C", 6}}, {{"Desc_Cable_C", 20}}, "Сборщик"};
    gameData.addRecipe("Desc_Cable_C", recipe);
    
    // 12. Кабель из быстрой проволоки
    recipe = {"Кабель из быстрой проволоки", "Recipe_Alternate_Cable_2", 24.0, {{"Desc_Quickwire_C", 3}, {"Desc_Rubber_C", 2}}, {{"Desc_Cable_C", 11}}, "Сборщик"};
    gameData.addRecipe("Desc_Cable_C", recipe);
    
    // 13. Катериевая быстрая проволока
    recipe = {"Катериевая быстрая проволока", "Recipe_Alternate_Quickwire", 8.0, {{"Desc_CateriumIngot_C", 1}, {"Desc_CopperIngot_C", 5}}, {{"Desc_Quickwire_C", 12}}, "Сборщик"};
    gameData.addRecipe("Desc_Quickwire_C", recipe);
    
    // 14. Мокрый бетон
    recipe = {"Мокрый бетон", "Recipe_Alternate_Concrete", 3.0, {{"Desc_Limestone_C", 6}, {"Desc_Water_C", 5}}, {{"Desc_Concrete_C", 4}}, "Очиститель"};
    gameData.addRecipe("Desc_Concrete_C", recipe);
    
    // 15. Мелкий бетон
    recipe = {"Мелкий бетон", "Recipe_Alternate_Concrete_2", 12.0, {{"Desc_Silica_C", 3}, {"Desc_Limestone_C", 12}}, {{"Desc_Concrete_C", 10}}, "Сборщик"};
    gameData.addRecipe("Desc_Concrete_C", recipe);
    
    // 16. Дешевый кремнезем
    recipe = {"Дешевый кремнезем", "Recipe_Alternate_Silica", 16.0, {{"Desc_RawQuartz_C", 3}, {"Desc_Limestone_C", 5}}, {{"Desc_Silica_C", 7}}, "Сборщик"};
    gameData.addRecipe("Desc_Silica_C", recipe);

    // ===== СТАНДАРТНЫЕ ДЕТАЛИ (20 рецептов) =====
    
    // 17. Прошитая железная пластина
    recipe = {"Прошитая железная пластина", "Recipe_Alternate_ReinforcedIronPlate_1", 24.0, {{"Desc_IronPlate_C", 10}, {"Desc_Wire_C", 20}}, {{"Desc_ReinforcedIronPlate_C", 3}}, "Сборщик"};
    gameData.addRecipe("Desc_ReinforcedIronPlate_C", recipe);
    
    // 18. Болтовая железная пластина
    recipe = {"Болтовая железная пластина", "Recipe_Alternate_ReinforcedIronPlate_2", 12.0, {{"Desc_IronPlate_C", 18}, {"Desc_Screw_C", 50}}, {{"Desc_ReinforcedIronPlate_C", 3}}, "Сборщик"};
    gameData.addRecipe("Desc_ReinforcedIronPlate_C", recipe);
    
    // 19. Стальной ротор
    recipe = {"Стальной ротор", "Recipe_Alternate_Rotor", 12.0, {{"Desc_SteelPipe_C", 2}, {"Desc_Wire_C", 6}}, {{"Desc_Rotor_C", 1}}, "Сборщик"};
    gameData.addRecipe("Desc_Rotor_C", recipe);
    
    // 20. Медный ротор
    recipe = {"Медный ротор", "Recipe_Alternate_Rotor_2", 16.0, {{"Desc_CopperSheet_C", 6}, {"Desc_Screw_C", 52}}, {{"Desc_Rotor_C", 3}}, "Сборщик"};
    gameData.addRecipe("Desc_Rotor_C", recipe);
    
    // 21. Статор из быстрой проволоки
    recipe = {"Статор из быстрой проволоки", "Recipe_Alternate_Stator", 15.0, {{"Desc_SteelPipe_C", 4}, {"Desc_Quickwire_C", 15}}, {{"Desc_Stator_C", 2}}, "Сборщик"};
    gameData.addRecipe("Desc_Stator_C", recipe);
    
    // 22. Стальной каркас
    recipe = {"Стальной каркас", "Recipe_Alternate_ModularFrame", 60.0, {{"Desc_ReinforcedIronPlate_C", 2}, {"Desc_SteelPipe_C", 10}}, {{"Desc_ModularFrame_C", 3}}, "Сборщик"};
    gameData.addRecipe("Desc_ModularFrame_C", recipe);
    
    // 23. Железобетонная труба
    recipe = {"Железобетонная труба", "Recipe_Alternate_EncasedIndustrialBeam", 15.0, {{"Desc_SteelPipe_C", 7}, {"Desc_Concrete_C", 5}}, {{"Desc_EncasedIndustrialBeam_C", 1}}, "Сборщик"};
    gameData.addRecipe("Desc_EncasedIndustrialBeam_C", recipe);

    // ===== ЭЛЕКТРОНИКА (15 рецептов) =====
    
    // 24. Кремниевая микросхема
    recipe = {"Кремниевая микросхема", "Recipe_Alternate_CircuitBoard_1", 24.0, {{"Desc_CopperSheet_C", 11}, {"Desc_Silica_C", 11}}, {{"Desc_CircuitBoard_C", 5}}, "Сборщик"};
    gameData.addRecipe("Desc_CircuitBoard_C", recipe);
    
    // 25. Катериевая микросхема
    recipe = {"Катериевая микросхема", "Recipe_Alternate_CircuitBoard_2", 48.0, {{"Desc_Plastic_C", 12}, {"Desc_Quickwire_C", 30}}, {{"Desc_CircuitBoard_C", 8}}, "Сборщик"};
    gameData.addRecipe("Desc_CircuitBoard_C", recipe);
    
    // 26. Кристаллический компьютер
    recipe = {"Кристаллический компьютер", "Recipe_Alternate_Computer_1", 64.0, {{"Desc_CircuitBoard_C", 8}, {"Desc_CrystalOscillator_C", 3}}, {{"Desc_Computer_C", 3}}, "Сборщик"};
    gameData.addRecipe("Desc_Computer_C", recipe);
    
    // 27. Катериевый компьютер
    recipe = {"Катериевый компьютер", "Recipe_Alternate_Computer_2", 16.0, {{"Desc_CircuitBoard_C", 7}, {"Desc_Quickwire_C", 28}}, {{"Desc_Computer_C", 1}}, "Производитель"};
    gameData.addRecipe("Desc_Computer_C", recipe);
    
    // 28. Высокоскоростной соединитель из кварца
    recipe = {"Высокоскоростной соединитель из кварца", "Recipe_Alternate_HighSpeedConnector", 16.0, {{"Desc_Quickwire_C", 40}, {"Desc_QuartzCrystal_C", 1}, {"Desc_Cable_C", 8}}, {{"Desc_HighSpeedConnector_C", 1}}, "Производитель"};
    gameData.addRecipe("Desc_HighSpeedConnector_C", recipe);
    
    // 29. Изолированный кристаллический генератор
    recipe = {"Изолированный кристаллический генератор", "Recipe_Alternate_CrystalOscillator", 120.0, {{"Desc_QuartzCrystal_C", 18}, {"Desc_Rubber_C", 14}, {"Desc_HighSpeedConnector_C", 1}}, {{"Desc_CrystalOscillator_C", 1}}, "Производитель"};
    gameData.addRecipe("Desc_CrystalOscillator_C", recipe);

    // ===== ПРОМЫШЛЕННЫЕ ДЕТАЛИ (12 рецептов) =====
    
    // 30. Жесткий мотор
    recipe = {"Жесткий мотор", "Recipe_Alternate_Motor_1", 48.0, {{"Desc_Rotor_C", 3}, {"Desc_Stator_C", 3}, {"Desc_CrystalOscillator_C", 1}}, {{"Desc_Motor_C", 6}}, "Производитель"};
    gameData.addRecipe("Desc_Motor_C", recipe);
    
    // 31. Электрический мотор
    recipe = {"Электрический мотор", "Recipe_Alternate_Motor_2", 16.0, {{"Desc_ElectromagneticControlRod_C", 1}, {"Desc_Rotor_C", 2}}, {{"Desc_Motor_C", 2}}, "Сборщик"};
    gameData.addRecipe("Desc_Motor_C", recipe);
    
    // 32. Тяжелый железобетонный каркас
    recipe = {"Тяжелый железобетонный каркас", "Recipe_Alternate_ModularFrameHeavy", 64.0, {{"Desc_ModularFrame_C", 8}, {"Desc_EncasedIndustrialBeam_C", 10}, {"Desc_SteelPipe_C", 36}, {"Desc_Concrete_C", 22}}, {{"Desc_ModularFrameHeavy_C", 3}}, "Производитель"};
    gameData.addRecipe("Desc_ModularFrameHeavy_C", recipe);
    
    // 33. Турбо электрический мотор
    recipe = {"Турбо электрический мотор", "Recipe_Alternate_TurboMotor_1", 64.0, {{"Desc_Motor_C", 7}, {"Desc_RadioControlUnit_C", 9}, {"Desc_ElectromagneticControlRod_C", 5}, {"Desc_Rotor_C", 7}}, {{"Desc_MotorLightweight_C", 3}}, "Производитель"};
    gameData.addRecipe("Desc_MotorLightweight_C", recipe);

    // ===== ЖИДКОСТИ И ХИМИКАТЫ (25 рецептов) =====
    
    // 34. Переработанный пластик
    recipe = {"Переработанный пластик", "Recipe_Alternate_Plastic_1", 12.0, {{"Desc_Rubber_C", 6}, {"Desc_HeavyOilResidue_C", 6}}, {{"Desc_Plastic_C", 12}}, "Очиститель"};
    gameData.addRecipe("Desc_Plastic_C", recipe);
    
    // 35. Переработанная резина
    recipe = {"Переработанная резина", "Recipe_Alternate_Rubber_1", 12.0, {{"Desc_Plastic_C", 6}, {"Desc_HeavyOilResidue_C", 6}}, {{"Desc_Rubber_C", 12}}, "Очиститель"};
    gameData.addRecipe("Desc_Rubber_C", recipe);
    
    // 36. Турботопливо
    recipe = {"Турботопливо", "Recipe_Alternate_Turbofuel", 16.0, {{"Desc_Fuel_C", 6}, {"Desc_CompactedCoal_C", 4}}, {{"Desc_TurboFuel_C", 5}}, "Очиститель"};
    gameData.addRecipe("Desc_TurboFuel_C", recipe);
    
    // 37. Смешанное турботопливо
    recipe = {"Смешанное турботопливо", "Recipe_Alternate_Turbofuel_2", 8.0, {{"Desc_HeavyOilResidue_C", 4}, {"Desc_Fuel_C", 2}, {"Desc_Sulfur_C", 3}}, {{"Desc_TurboFuel_C", 4}}, "Очиститель"};
    gameData.addRecipe("Desc_TurboFuel_C", recipe);

    // ===== ЯДЕРНЫЕ МАТЕРИАЛЫ (8 рецептов) =====
    
    // 38. Урановые топливные элементы с железом
    recipe = {"Урановые топливные элементы с железом", "Recipe_Alternate_UraniumCell_1", 150.0, {{"Desc_Uranium_C", 5}, {"Desc_IronPlate_C", 9}, {"Desc_Concrete_C", 45}}, {{"Desc_UraniumCell_C", 4}}, "Сборщик"};
    gameData.addRecipe("Desc_UraniumCell_C", recipe);
    
    // 39. Урановые топливные стержни с железом
    recipe = {"Урановые топливные стержни с железом", "Recipe_Alternate_NuclearFuelRod_1", 150.0, {{"Desc_UraniumCell_C", 20}, {"Desc_IronPlate_C", 1}, {"Desc_EncasedIndustrialBeam_C", 1}}, {{"Desc_NuclearFuelRod_C", 1}}, "Производитель"};
    gameData.addRecipe("Desc_NuclearFuelRod_C", recipe);

    // ===== ПРОДВИНУТЫЕ МАТЕРИАЛЫ (20 рецептов) =====
    
    // 40. Радиатор с кремнеземом
    recipe = {"Радиатор с кремнеземом", "Recipe_Alternate_HeatSink_1", 8.0, {{"Desc_AlcladAluminumSheet_C", 5}, {"Desc_CopperSheet_C", 3}, {"Desc_Silica_C", 8}}, {{"Desc_HeatSink_C", 2}}, "Сборщик"};
    gameData.addRecipe("Desc_HeatSink_C", recipe);
    
    // 41. Кулер с медью
    recipe = {"Кулер с медью", "Recipe_Alternate_HeatSink_2", 10.0, {{"Desc_CopperSheet_C", 10}, {"Desc_CopperIngot_C", 7}}, {{"Desc_HeatSink_C", 1}}, "Сборщик"};
    gameData.addRecipe("Desc_HeatSink_C", recipe);

    // 42. Алюминиевый каркас
    recipe = {"Алюминиевый каркас", "Recipe_Alternate_ModularFrameLightweight", 64.0, {{"Desc_AluminumCasing_C", 14}, {"Desc_AlcladAluminumSheet_C", 3}}, {{"Desc_ModularFrameLightweight_C", 2}}, "Производитель"};
    gameData.addRecipe("Desc_ModularFrameLightweight_C", recipe);

    // 43. Радиоактивная паста
    recipe = {"Радиоактивная паста", "Recipe_Alternate_NuclearPasta_1", 120.0, {{"Desc_CopperPowder_C", 100}, {"Desc_PressureConversionCube_C", 1}}, {{"Desc_NuclearPasta_C", 1}}, "Ускоритель частиц"};
    gameData.addRecipe("Desc_NuclearPasta_C", recipe);

    // ===== ДОПОЛНИТЕЛЬНЫЕ ЭЛЕКТРОНИКА (15 рецептов) =====
    
    // 44. Микросхема из полимера
    recipe = {"Микросхема из полимера", "Recipe_Alternate_CircuitBoard_3", 30.0, {{"Desc_Plastic_C", 3}, {"Desc_Wire_C", 4}}, {{"Desc_CircuitBoard_C", 1}}, "Сборщик"};
    gameData.addRecipe("Desc_CircuitBoard_C", recipe);

    // 45. Суперкомпьютер
    recipe = {"Суперкомпьютер", "Recipe_Alternate_Computer_3", 50.0, {{"Desc_Computer_C", 3}, {"Desc_HighSpeedConnector_C", 2}}, {{"Desc_Computer_C", 5}}, "Сборщик"};
    gameData.addRecipe("Desc_Computer_C", recipe);

    // 46. Электромагнитное управление
    recipe = {"Электромагнитное управление", "Recipe_Alternate_ElectromagneticControlRod", 30.0, {{"Desc_Stator_C", 3}, {"Desc_HighSpeedConnector_C", 2}}, {{"Desc_ElectromagneticControlRod_C", 2}}, "Сборщик"};
    gameData.addRecipe("Desc_ElectromagneticControlRod_C", recipe);

    // 47. Радиоуправление
    recipe = {"Радиоуправление", "Recipe_Alternate_RadioControlUnit", 48.0, {{"Desc_CrystalOscillator_C", 1}, {"Desc_CircuitBoard_C", 10}, {"Desc_AluminumCasing_C", 60}, {"Desc_Rubber_C", 30}}, {{"Desc_RadioControlUnit_C", 8}}, "Производитель"};
    gameData.addRecipe("Desc_RadioControlUnit_C", recipe);

    // ===== ДОПОЛНИТЕЛЬНЫЕ СТРОИТЕЛЬНЫЕ МАТЕРИАЛЫ (10 рецептов) =====
    
    // 48. Железобетонная балка
    recipe = {"Железобетонная балка", "Recipe_Alternate_EncasedIndustrialBeam_2", 18.0, {{"Desc_SteelBeam_C", 6}, {"Desc_Concrete_C", 8}}, {{"Desc_EncasedIndustrialBeam_C", 1}}, "Сборщик"};
    gameData.addRecipe("Desc_EncasedIndustrialBeam_C", recipe);

    // 49. Алюминиевая балка
    recipe = {"Алюминиевая балка", "Recipe_Alternate_EncasedIndustrialBeam_3", 15.0, {{"Desc_AluminumCasing_C", 3}, {"Desc_SteelBeam_C", 1}}, {{"Desc_EncasedIndustrialBeam_C", 1}}, "Сборщик"};
    gameData.addRecipe("Desc_EncasedIndustrialBeam_C", recipe);

    // 50. Стальная труба
    recipe = {"Стальная труба", "Recipe_Alternate_SteelPipe", 6.0, {{"Desc_SteelIngot_C", 3}}, {{"Desc_SteelPipe_C", 2}}, "Конструктор"};
    gameData.addRecipe("Desc_SteelPipe_C", recipe);

    // 51. Медная трубка
    recipe = {"Медная трубка", "Recipe_Alternate_SteelPipe_2", 4.0, {{"Desc_CopperIngot_C", 2}}, {{"Desc_SteelPipe_C", 1}}, "Конструктор"};
    gameData.addRecipe("Desc_SteelPipe_C", recipe);

    // ===== ДОПОЛНИТЕЛЬНЫЕ СЛИТКИ (8 рецептов) =====
    
    // 52. Железный сплав
    recipe = {"Железный сплав", "Recipe_Alternate_IngotIron_2", 6.0, {{"Desc_IronOre_C", 2}, {"Desc_CopperOre_C", 2}}, {{"Desc_IronIngot_C", 5}}, "Литейная"};
    gameData.addRecipe("Desc_IronIngot_C", recipe);

    // 53. Медный сплав
    recipe = {"Медный сплав", "Recipe_Alternate_IngotCopper_2", 12.0, {{"Desc_CopperOre_C", 10}, {"Desc_IronOre_C", 5}}, {{"Desc_CopperIngot_C", 20}}, "Литейная"};
    gameData.addRecipe("Desc_CopperIngot_C", recipe);

    // 54. Базовый алюминий
    recipe = {"Базовый алюминий", "Recipe_Alternate_IngotAluminum_2", 8.0, {{"Desc_Bauxite_C", 12}, {"Desc_Water_C", 18}}, {{"Desc_AluminumScrap_C", 20}, {"Desc_Water_C", 5}}, "Очиститель"};
    gameData.addRecipe("Desc_AluminumScrap_C", recipe);

    // ===== ТОПЛИВО И ЭНЕРГЕТИКА (12 рецептов) =====
    
    // 55. Компактированный уголь
    recipe = {"Компактированный уголь", "Recipe_Alternate_CompactedCoal", 12.0, {{"Desc_Coal_C", 5}, {"Desc_Sulfur_C", 5}}, {{"Desc_CompactedCoal_C", 5}}, "Сборщик"};
    gameData.addRecipe("Desc_CompactedCoal_C", recipe);

    // 56. Биотопливо
    recipe = {"Биотопливо", "Recipe_Alternate_Biofuel", 4.0, {{"Desc_Biomass_C", 8}}, {{"Desc_Biofuel_C", 4}}, "Конструктор"};
    gameData.addRecipe("Desc_Biofuel_C", recipe);

    // 57. Жидкое топливо
    recipe = {"Жидкое топливо", "Recipe_Alternate_LiquidFuel", 6.0, {{"Desc_LiquidOil_C", 6}}, {{"Desc_Fuel_C", 4}, {"Desc_PolymerResin_C", 3}}, "Очиститель"};
    gameData.addRecipe("Desc_Fuel_C", recipe);

    // 58. Остаточное топливо
    recipe = {"Остаточное топливо", "Recipe_Alternate_ResidualFuel", 6.0, {{"Desc_HeavyOilResidue_C", 6}}, {{"Desc_Fuel_C", 4}}, "Очиститель"};
    gameData.addRecipe("Desc_Fuel_C", recipe);

    // 59. Остаточная резина
    recipe = {"Остаточная резина", "Recipe_Alternate_ResidualRubber", 6.0, {{"Desc_PolymerResin_C", 4}, {"Desc_Water_C", 4}}, {{"Desc_Rubber_C", 2}}, "Очиститель"};
    gameData.addRecipe("Desc_Rubber_C", recipe);

    // 60. Остаточный пластик
    recipe = {"Остаточный пластик", "Recipe_Alternate_ResidualPlastic", 6.0, {{"Desc_PolymerResin_C", 6}, {"Desc_Water_C", 2}}, {{"Desc_Plastic_C", 2}}, "Очиститель"};
    gameData.addRecipe("Desc_Plastic_C", recipe);

    // ===== КВАРЦ И КРИСТАЛЛЫ (8 рецептов) =====
    
    // 61. Чистый кварц
    recipe = {"Чистый кварц", "Recipe_Alternate_PureQuartz", 8.0, {{"Desc_RawQuartz_C", 9}, {"Desc_Water_C", 5}}, {{"Desc_QuartzCrystal_C", 7}}, "Очиститель"};
    gameData.addRecipe("Desc_QuartzCrystal_C", recipe);

    // 62. Кварцевые осколки
    recipe = {"Кварцевые осколки", "Recipe_Alternate_QuartzCrystal", 8.0, {{"Desc_RawQuartz_C", 5}}, {{"Desc_QuartzCrystal_C", 3}}, "Конструктор"};
    gameData.addRecipe("Desc_QuartzCrystal_C", recipe);

    // 63. Кристаллический сбалансированный генератор
    recipe = {"Кристаллический сбалансированный генератор", "Recipe_Alternate_CrystalOscillator_2", 120.0, {{"Desc_QuartzCrystal_C", 9}, {"Desc_Cable_C", 5}, {"Desc_ReinforcedIronPlate_C", 1}}, {{"Desc_CrystalOscillator_C", 1}}, "Производитель"};
    gameData.addRecipe("Desc_CrystalOscillator_C", recipe);

    // ===== МАСЛО И НЕФТЕПРОДУКТЫ (10 рецептов) =====
    
    // 64. Полимерная смола
    recipe = {"Полимерная смола", "Recipe_Alternate_PolymerResin", 6.0, {{"Desc_LiquidOil_C", 3}}, {{"Desc_PolymerResin_C", 13}, {"Desc_HeavyOilResidue_C", 2}}, "Очиститель"};
    gameData.addRecipe("Desc_PolymerResin_C", recipe);

    // 65. Разбавленное топливо
    recipe = {"Разбавленное топливо", "Recipe_Alternate_DilutedFuel", 6.0, {{"Desc_HeavyOilResidue_C", 5}, {"Desc_Water_C", 10}}, {{"Desc_Fuel_C", 10}}, "Очиститель"};
    gameData.addRecipe("Desc_Fuel_C", recipe);

    // 66. Тяжелое масляное остаток
    recipe = {"Тяжелое масляное остаток", "Recipe_Alternate_HeavyOilResidue", 6.0, {{"Desc_LiquidOil_C", 3}}, {{"Desc_HeavyOilResidue_C", 4}, {"Desc_PolymerResin_C", 2}}, "Очиститель"};
    gameData.addRecipe("Desc_HeavyOilResidue_C", recipe);

    // 67. Нефтекокс
    recipe = {"Нефтекокс", "Recipe_Alternate_PetroleumCoke", 6.0, {{"Desc_HeavyOilResidue_C", 4}}, {{"Desc_PetroleumCoke_C", 12}}, "Очиститель"};
    gameData.addRecipe("Desc_PetroleumCoke_C", recipe);

    // ===== БАТАРЕИ И АККУМУЛЯТОРЫ (6 рецептов) =====
    
    // 68. Классическая батарея
    recipe = {"Классическая батарея", "Recipe_Alternate_Battery_1", 8.0, {{"Desc_Sulfur_C", 6}, {"Desc_AlcladAluminumSheet_C", 7}, {"Desc_Plastic_C", 8}, {"Desc_Wire_C", 12}}, {{"Desc_Battery_C", 4}}, "Производитель"};
    gameData.addRecipe("Desc_Battery_C", recipe);

    // 69. Алюминиевая батарея
    recipe = {"Алюминиевая батарея", "Recipe_Alternate_Battery_2", 12.0, {{"Desc_AluminumIngot_C", 17}, {"Desc_CopperSheet_C", 10}, {"Desc_Plastic_C", 9}, {"Desc_Wire_C", 28}}, {{"Desc_Battery_C", 5}}, "Производитель"};
    gameData.addRecipe("Desc_Battery_C", recipe);

    // ===== УРАНОВЫЕ И ЯДЕРНЫЕ (8 рецептов) =====
    
    // 70. Инфузированный урановый элемент
    recipe = {"Инфузированный урановый элемент", "Recipe_Alternate_UraniumCell_2", 150.0, {{"Desc_Uranium_C", 25}, {"Desc_Silica_C", 15}, {"Desc_Sulfur_C", 25}, {"Desc_Quickwire_C", 75}}, {{"Desc_UraniumCell_C", 20}}, "Производитель"};
    gameData.addRecipe("Desc_UraniumCell_C", recipe);

    // 71. Урановые топливные стержни с титаном
    recipe = {"Урановые топливные стержни с титаном", "Recipe_Alternate_NuclearFuelRod_2", 300.0, {{"Desc_UraniumCell_C", 25}, {"Desc_AlcladAluminumSheet_C", 4}, {"Desc_EncasedIndustrialBeam_C", 5}}, {{"Desc_NuclearFuelRod_C", 3}}, "Производитель"};
    gameData.addRecipe("Desc_NuclearFuelRod_C", recipe);

    // 72. Плутониевые топливные стержни
    recipe = {"Плутониевые топливные стержни", "Recipe_Alternate_PlutoniumFuelRod", 600.0, {{"Desc_PlutoniumPellet_C", 30}, {"Desc_SteelBeam_C", 18}, {"Desc_ElectromagneticControlRod_C", 6}, {"Desc_HeatSink_C", 10}}, {{"Desc_PlutoniumFuelRod_C", 1}}, "Производитель"};
    gameData.addRecipe("Desc_PlutoniumFuelRod_C", recipe);

    // 73. Плутониевые гранулы
    recipe = {"Плутониевые гранулы", "Recipe_Alternate_PlutoniumPellet", 60.0, {{"Desc_NuclearWaste_C", 25}, {"Desc_UraniumCell_C", 25}}, {{"Desc_PlutoniumPellet_C", 15}}, "Ускоритель частиц"};
    gameData.addRecipe("Desc_PlutoniumPellet_C", recipe);

    // ===== МЕДНЫЕ ИЗДЕЛИЯ (6 рецептов) =====
    
    // 74. Медный лист из слитков
    recipe = {"Медный лист из слитков", "Recipe_Alternate_CopperSheet", 6.0, {{"Desc_CopperIngot_C", 2}}, {{"Desc_CopperSheet_C", 1}}, "Конструктор"};
    gameData.addRecipe("Desc_CopperSheet_C", recipe);

    // 75. Стальной лист
    recipe = {"Стальной лист", "Recipe_Alternate_SteelSheet", 12.0, {{"Desc_SteelIngot_C", 3}, {"Desc_IronIngot_C", 5}}, {{"Desc_CopperSheet_C", 4}}, "Сборщик"};
    gameData.addRecipe("Desc_CopperSheet_C", recipe);

    // 76. Медный порошок
    recipe = {"Медный порошок", "Recipe_Alternate_CopperPowder", 16.0, {{"Desc_CopperIngot_C", 50}}, {{"Desc_CopperPowder_C", 50}}, "Конструктор"};
    gameData.addRecipe("Desc_CopperPowder_C", recipe);

    // ===== АЛЮМИНИЕВЫЕ ИЗДЕЛИЯ (10 рецептов) =====
    
    // 77. Алюминиевые листы
    recipe = {"Алюминиевые листы", "Recipe_Alternate_AlcladAluminumSheet", 6.0, {{"Desc_AluminumIngot_C", 3}, {"Desc_CopperIngot_C", 1}}, {{"Desc_AlcladAluminumSheet_C", 3}}, "Сборщик"};
    gameData.addRecipe("Desc_AlcladAluminumSheet_C", recipe);

    // 78. Алюминиевый корпус
    recipe = {"Алюминиевый корпус", "Recipe_Alternate_AluminumCasing", 8.0, {{"Desc_AluminumIngot_C", 4}}, {{"Desc_AluminumCasing_C", 3}}, "Конструктор"};
    gameData.addRecipe("Desc_AluminumCasing_C", recipe);

    // 79. Очищенный алюминий
    recipe = {"Очищенный алюминий", "Recipe_Alternate_AluminumScrap_2", 3.0, {{"Desc_AluminumOre_C", 4}, {"Desc_NitricAcid_C", 2}}, {{"Desc_AluminumScrap_C", 6}, {"Desc_Water_C", 2}}, "Очиститель"};
    gameData.addRecipe("Desc_AluminumScrap_C", recipe);

    // ===== СЛОЖНЫЕ КОМПОНЕНТЫ (15 рецептов) =====
    
    // 80. Тепловые трубки
    recipe = {"Тепловые трубки", "Recipe_Alternate_CoolingSystem", 24.0, {{"Desc_HeatSink_C", 2}, {"Desc_Rubber_C", 5}, {"Desc_Water_C", 5}, {"Desc_NitrogenGas_C", 25}}, {{"Desc_CoolingSystem_C", 1}}, "Сборщик"};
    gameData.addRecipe("Desc_CoolingSystem_C", recipe);

    // 81. Плавкие модули
    recipe = {"Плавкие модули", "Recipe_Alternate_ModularEngine", 60.0, {{"Desc_Motor_C", 2}, {"Desc_Rubber_C", 15}, {"Desc_SmartPlating_C", 2}}, {{"Desc_ModularEngine_C", 1}}, "Производитель"};
    gameData.addRecipe("Desc_ModularEngine_C", recipe);

    // 82. Адаптивные схемы управления
    recipe = {"Адаптивные схемы управления", "Recipe_Alternate_AdaptiveControlUnit", 120.0, {{"Desc_AutomatedWiring_C", 15}, {"Desc_CircuitBoard_C", 10}, {"Desc_HeavyModularFrame_C", 2}, {"Desc_Computer_C", 2}}, {{"Desc_AdaptiveControlUnit_C", 2}}, "Производитель"};
    gameData.addRecipe("Desc_AdaptiveControlUnit_C", recipe);

    // 83. Сверхпроводящие магниты
    recipe = {"Сверхпроводящие магниты", "Recipe_Alternate_ElectromagneticControlRod_2", 60.0, {{"Desc_ElectromagneticControlRod_C", 3}, {"Desc_Wire_C", 25}, {"Desc_Battery_C", 1}}, {{"Desc_ElectromagneticControlRod_C", 5}}, "Сборщик"};
    gameData.addRecipe("Desc_ElectromagneticControlRod_C", recipe);

    // ===== УМНЫЕ МАТЕРИАЛЫ (8 рецептов) =====
    
    // 84. Гибкие рамки
    recipe = {"Гибкие рамки", "Recipe_Alternate_ModularFrameLightweight_2", 64.0, {{"Desc_ModularFrame_C", 1}, {"Desc_SteelBeam_C", 6}, {"Desc_Rubber_C", 8}}, {{"Desc_ModularFrameLightweight_C", 2}}, "Производитель"};
    gameData.addRecipe("Desc_ModularFrameLightweight_C", recipe);

    // 85. Умная обшивка
    recipe = {"Умная обшивка", "Recipe_Alternate_SmartPlating", 30.0, {{"Desc_ReinforcedIronPlate_C", 1}, {"Desc_Rotor_C", 1}}, {{"Desc_SmartPlating_C", 1}}, "Сборщик"};
    gameData.addRecipe("Desc_SmartPlating_C", recipe);

    // 86. Пластичная умная обшивка
    recipe = {"Пластичная умная обшивка", "Recipe_Alternate_SmartPlating_2", 24.0, {{"Desc_ReinforcedIronPlate_C", 2}, {"Desc_Rotor_C", 2}, {"Desc_Plastic_C", 3}}, {{"Desc_SmartPlating_C", 2}}, "Производитель"};
    gameData.addRecipe("Desc_SmartPlating_C", recipe);

    // ===== АВТОМАТИЗИРОВАННЫЕ КОМПОНЕНТЫ (6 рецептов) =====
    
    // 87. Автоматическая проводка
    recipe = {"Автоматическая проводка", "Recipe_Alternate_AutomatedWiring", 24.0, {{"Desc_Stator_C", 1}, {"Desc_Cable_C", 20}}, {{"Desc_AutomatedWiring_C", 1}}, "Сборщик"};
    gameData.addRecipe("Desc_AutomatedWiring_C", recipe);

    // 88. Высокоскоростная проводка
    recipe = {"Высокоскоростная проводка", "Recipe_Alternate_AutomatedWiring_2", 32.0, {{"Desc_Stator_C", 3}, {"Desc_Wire_C", 50}, {"Desc_HighSpeedConnector_C", 1}}, {{"Desc_AutomatedWiring_C", 3}}, "Производитель"};
    gameData.addRecipe("Desc_AutomatedWiring_C", recipe);

    // ===== УНИВЕРСАЛЬНЫЕ МАТЕРИАЛЫ (10 рецептов) =====
    
    // 89. Универсальный корпус
    recipe = {"Универсальный корпус", "Recipe_Alternate_VersatileFramework", 24.0, {{"Desc_ModularFrame_C", 3}, {"Desc_SteelBeam_C", 30}}, {{"Desc_VersatileFramework_C", 5}}, "Сборщик"};
    gameData.addRecipe("Desc_VersatileFramework_C", recipe);

    // 90. Гибкий универсальный корпус
    recipe = {"Гибкий универсальный корпус", "Recipe_Alternate_VersatileFramework_2", 16.0, {{"Desc_ModularFrame_C", 1}, {"Desc_SteelBeam_C", 12}, {"Desc_Rubber_C", 3}}, {{"Desc_VersatileFramework_C", 2}}, "Производитель"};
    gameData.addRecipe("Desc_VersatileFramework_C", recipe);

    // ===== ГАЗЫ И КРИОГЕННЫЕ МАТЕРИАЛЫ (5 рецептов) =====
    
    // 91. Азотный газ
    recipe = {"Азотный газ", "Recipe_Alternate_NitrogenGas", 12.0, {{"Desc_Water_C", 12}}, {{"Desc_NitrogenGas_C", 45}}, "Очиститель"};
    gameData.addRecipe("Desc_NitrogenGas_C", recipe);

    // 92. Охлаждающая смесь
    recipe = {"Охлаждающая смесь", "Recipe_Alternate_CoolingSystem_2", 10.0, {{"Desc_Water_C", 5}, {"Desc_NitrogenGas_C", 25}}, {{"Desc_CoolingSystem_C", 1}}, "Очиститель"};
    gameData.addRecipe("Desc_CoolingSystem_C", recipe);

    // ===== СИНТЕТИЧЕСКИЕ МАТЕРИАЛЫ (8 рецептов) =====
    
    // 93. Синтетическая ткань
    recipe = {"Синтетическая ткань", "Recipe_Alternate_Fabric", 4.0, {{"Desc_PolymerResin_C", 1}, {"Desc_Water_C", 1}}, {{"Desc_Fabric_C", 1}}, "Очиститель"};
    gameData.addRecipe("Desc_Fabric_C", recipe);

    // 94. Переработанная ткань
    recipe = {"Переработанная ткань", "Recipe_Alternate_Fabric_2", 12.0, {{"Desc_Polyester_C", 5}, {"Desc_Water_C", 10}}, {{"Desc_Fabric_C", 15}}, "Очиститель"};
    gameData.addRecipe("Desc_Fabric_C", recipe);

    // 95. Полиэстер
    recipe = {"Полиэстер", "Recipe_Alternate_Polyester", 6.0, {{"Desc_PolymerResin_C", 3}, {"Desc_Water_C", 3}}, {{"Desc_Polyester_C", 1}}, "Очиститель"};
    gameData.addRecipe("Desc_Polyester_C", recipe);

    // ===== КИСЛОТЫ И ХИМИЧЕСКИЕ РЕАГЕНТЫ (5 рецептов) =====
    
    // 96. Азотная кислота
    recipe = {"Азотная кислота", "Recipe_Alternate_NitricAcid", 6.0, {{"Desc_NitrogenGas_C", 12}, {"Desc_Water_C", 3}, {"Desc_IronPlate_C", 1}}, {{"Desc_NitricAcid_C", 3}}, "Очиститель"};
    gameData.addRecipe("Desc_NitricAcid_C", recipe);

    // 97. Алюминиевые растворители
    recipe = {"Алюминиевые растворители", "Recipe_Alternate_AluminaSolution", 6.0, {{"Desc_Bauxite_C", 12}, {"Desc_Water_C", 18}}, {{"Desc_AluminaSolution_C", 12}, {"Desc_Silica_C", 5}}, "Очиститель"};
    gameData.addRecipe("Desc_AluminaSolution_C", recipe);

    // ===== СУПЕР МАТЕРИАЛЫ (10 рецептов) =====
    
    // 98. Тепловой суперпроводник
    recipe = {"Тепловой суперпроводник", "Recipe_Alternate_ThermalPropulsionRocket", 120.0, {{"Desc_ModularEngine_C", 5}, {"Desc_TurboMotor_C", 2}, {"Desc_CoolingSystem_C", 6}, {"Desc_HeavyModularFrame_C", 3}}, {{"Desc_ThermalPropulsionRocket_C", 2}}, "Производитель"};
    gameData.addRecipe("Desc_ThermalPropulsionRocket_C", recipe);

    // 99. Супер двигатель
    recipe = {"Супер двигатель", "Recipe_Alternate_TurboMotor_2", 32.0, {{"Desc_CoolingSystem_C", 4}, {"Desc_RadioControlUnit_C", 2}, {"Desc_Motor_C", 4}, {"Desc_Rubber_C", 24}}, {{"Desc_MotorLightweight_C", 1}}, "Производитель"};
    gameData.addRecipe("Desc_MotorLightweight_C", recipe);

    // 100. Квантовые кристаллы
    recipe = {"Квантовые кристаллы", "Recipe_Alternate_QuartzCrystal_2", 60.0, {{"Desc_RawQuartz_C", 25}, {"Desc_Coal_C", 25}}, {{"Desc_QuartzCrystal_C", 25}}, "Ускоритель частиц"};
    gameData.addRecipe("Desc_QuartzCrystal_C", recipe);

    // ===== ЭКЗОТИЧЕСКИЕ МАТЕРИАЛЫ (13 рецептов) =====
    
    // 101. Нестабильная полиморфная материя
    recipe = {"Нестабильная полиморфная материя", "Recipe_Alternate_SAMFluctuator", 240.0, {{"Desc_SAMIngot_C", 60}, {"Desc_Wire_C", 50}, {"Desc_SteelBeam_C", 30}}, {{"Desc_SAMFluctuator_C", 10}}, "Ускоритель частиц"};
    gameData.addRecipe("Desc_SAMFluctuator_C", recipe);

    // 102. Синтетические алмазы
    recipe = {"Синтетические алмазы", "Recipe_Alternate_Diamonds", 300.0, {{"Desc_Coal_C", 600}}, {{"Desc_Diamonds_C", 5}}, "Ускоритель частиц"};
    gameData.addRecipe("Desc_Diamonds_C", recipe);

    // 103. Время-пространственные усилители
    recipe = {"Время-пространственные усилители", "Recipe_Alternate_SpaceElevatorPart_1", 600.0, {{"Desc_SAMFluctuator_C", 25}, {"Desc_SuperComputer_C", 10}, {"Desc_Diamonds_C", 50}, {"Desc_ExcitedPhotonGravityComputer_C", 10}}, {{"Desc_SpaceElevatorPart_1_C", 1}}, "Квантовый кодер"};
    gameData.addRecipe("Desc_SpaceElevatorPart_1_C", recipe);

    // 104. Гиперсферические модули
    recipe = {"Гиперсферические модули", "Recipe_Alternate_SpaceElevatorPart_2", 600.0, {{"Desc_SAMFluctuator_C", 10}, {"Desc_SuperComputer_C", 3}, {"Desc_Diamonds_C", 40}, {"Desc_ExcitedPhotonGravityComputer_C", 3}}, {{"Desc_SpaceElevatorPart_2_C", 1}}, "Квантовый кодер"};
    gameData.addRecipe("Desc_SpaceElevatorPart_2_C", recipe);

    // 105. Квантовые компьютеры
    recipe = {"Квантовые компьютеры", "Recipe_Alternate_SuperComputer", 50.0, {{"Desc_Computer_C", 3}, {"Desc_HighSpeedConnector_C", 2}, {"Desc_SuperPosition_Oscillator_C", 1}, {"Desc_CoolingSystem_C", 2}}, {{"Desc_SuperComputer_C", 1}}, "Производитель"};
    gameData.addRecipe("Desc_SuperComputer_C", recipe);

    // 106. Суперпозиционные генераторы
    recipe = {"Суперпозиционные генераторы", "Recipe_Alternate_SuperPosition_Oscillator", 180.0, {{"Desc_DarkMatter_C", 20}, {"Desc_CrystalOscillator_C", 1}, {"Desc_AlcladAluminumSheet_C", 9}, {"Desc_ExcitedPhotonNeutron_C", 20}}, {{"Desc_SuperPosition_Oscillator_C", 1}}, "Квантовый кодер"};
    gameData.addRecipe("Desc_SuperPosition_Oscillator_C", recipe);

    // 107. Темная материя
    recipe = {"Темная материя", "Recipe_Alternate_DarkMatter", 60.0, {{"Desc_DarkMatterCrystal_C", 5}}, {{"Desc_DarkMatter_C", 50}}, "Ускоритель частиц"};
    gameData.addRecipe("Desc_DarkMatter_C", recipe);

    // 108. Кристаллы темной материи
    recipe = {"Кристаллы темной материи", "Recipe_Alternate_DarkMatterCrystal", 120.0, {{"Desc_Diamonds_C", 1}, {"Desc_DarkMatterResidue_C", 25}}, {{"Desc_DarkMatterCrystal_C", 1}}, "Ускоритель частиц"};
    gameData.addRecipe("Desc_DarkMatterCrystal_C", recipe);

    // 109. Остатки темной материи
    recipe = {"Остатки темной материи", "Recipe_Alternate_DarkMatterResidue", 60.0, {{"Desc_ReanimatedSAM_C", 25}}, {{"Desc_DarkMatterResidue_C", 200}}, "Конвертер"};
    gameData.addRecipe("Desc_DarkMatterResidue_C", recipe);

    // 110. Возбужденные фотонные нейтроны
    recipe = {"Возбужденные фотонные нейтроны", "Recipe_Alternate_ExcitedPhotonNeutron", 120.0, {{"Desc_CopperPowder_C", 100}, {"Desc_PressureConversionCube_C", 5}}, {{"Desc_ExcitedPhotonNeutron_C", 50}}, "Ускоритель частиц"};
    gameData.addRecipe("Desc_ExcitedPhotonNeutron_C", recipe);

    // 111. Гравитационные квантовые компьютеры
    recipe = {"Гравитационные квантовые компьютеры", "Recipe_Alternate_ExcitedPhotonGravityComputer", 600.0, {{"Desc_ExcitedPhotonNeutron_C", 50}, {"Desc_SuperComputer_C", 2}, {"Desc_DarkMatter_C", 25}, {"Desc_SAMFluctuator_C", 3}}, {{"Desc_ExcitedPhotonGravityComputer_C", 1}}, "Квантовый кодер"};
    gameData.addRecipe("Desc_ExcitedPhotonGravityComputer_C", recipe);

    // 112. Восстановленная САМ
    recipe = {"Восстановленная САМ", "Recipe_Alternate_ReanimatedSAM", 120.0, {{"Desc_SAMIngot_C", 4}}, {{"Desc_ReanimatedSAM_C", 30}}, "Конструктор"};
    gameData.addRecipe("Desc_ReanimatedSAM_C", recipe);

    // 113. Кубы преобразования давления
    recipe = {"Кубы преобразования давления", "Recipe_Alternate_PressureConversionCube", 60.0, {{"Desc_AluminumCasing_C", 1}, {"Desc_CrystalOscillator_C", 2}}, {{"Desc_PressureConversionCube_C", 1}}, "Сборщик"};
    gameData.addRecipe("Desc_PressureConversionCube_C", recipe);

    // Альт: Турботопливо из нефтяных остатков
    recipe = {"Турботопливо из остатков", "Recipe_Alternate_TurboFuel_2", 16.0, {{"Desc_HeavyOilResidue_C", 5}, {"Desc_CompactedCoal_C", 4}}, {{"Desc_TurboFuel_C", 4}}, "Очиститель"};
    gameData.addRecipe("Desc_TurboFuel_C", recipe);

    // ===== UPDATE 9 АЛЬТЕРНАТИВНЫЕ РЕЦЕПТЫ =====
    
    // Альт: Пластиковый ограничитель ИИ
    recipe = {"Пластиковый ограничитель ИИ", "Recipe_Alternate_AILimiter_Plastic", 15.0, {{"Desc_Plastic_C", 30}, {"Desc_Quickwire_C", 120}}, {{"Desc_AILimiter_C", 5}}, "Сборщик"};
    gameData.addRecipe("Desc_AILimiter_C", recipe);
    
    // Альт: Алюминиевый стержень
    recipe = {"Алюминиевый стержень", "Recipe_Alternate_AluminumRod", 8.0, {{"Desc_AluminumIngot_C", 1}}, {{"Desc_AluminumRod_C", 7}}, "Конструктор"};
    gameData.addRecipe("Desc_AluminumRod_C", recipe);
    
    // Альт: Алюминиевая балка
    recipe = {"Алюминиевая балка", "Recipe_Alternate_SteelBeam_Aluminum", 8.0, {{"Desc_AluminumIngot_C", 3}}, {{"Desc_SteelBeam_C", 3}}, "Конструктор"};
    gameData.addRecipe("Desc_SteelBeam_C", recipe);
    
    // Альт: Литая стальная балка
    recipe = {"Литая стальная балка", "Recipe_Alternate_SteelBeam_Molded", 5.0, {{"Desc_SteelIngot_C", 5}, {"Desc_Concrete_C", 2}}, {{"Desc_SteelBeam_C", 3}}, "Литейная"};
    gameData.addRecipe("Desc_SteelBeam_C", recipe);
    
    // Альт: Литая стальная пластина
    recipe = {"Литая стальная пластина", "Recipe_Alternate_SteelCastedPlate", 4.0, {{"Desc_SteelIngot_C", 1}, {"Desc_Plastic_C", 1}}, {{"Desc_SteelPlate_C", 3}}, "Литейная"};
    gameData.addRecipe("Desc_SteelPlate_C", recipe);
    
    // Альт: Железная стальная труба
    recipe = {"Железная стальная труба", "Recipe_Alternate_SteelPipe_Iron", 12.0, {{"Desc_IronIngot_C", 20}, {"Desc_Concrete_C", 5}}, {{"Desc_SteelPipe_C", 10}}, "Конструктор"};
    gameData.addRecipe("Desc_SteelPipe_C", recipe);
    
    // Альт: Литая стальная труба
    recipe = {"Литая стальная труба", "Recipe_Alternate_SteelPipe_Molded", 5.0, {{"Desc_SteelIngot_C", 3}, {"Desc_Concrete_C", 3}}, {{"Desc_SteelPipe_C", 5}}, "Литейная"};
    gameData.addRecipe("Desc_SteelPipe_C", recipe);

    // ===== TIER 9 АЛЬТЕРНАТИВНЫЕ РЕЦЕПТЫ =====
    
    // Альт: Кристаллизация темной материи
    recipe = {"Кристаллизация темной материи", "Recipe_Alternate_DarkMatter_Crystallization", 3.0, {{"Desc_DarkMatterResidue_C", 10}, {"Desc_Diamonds_C", 1}}, {{"Desc_DarkMatterCrystal_C", 3}}, "Ускоритель частиц"};
    gameData.addRecipe("Desc_DarkMatterCrystal_C", recipe);
    
    // Альт: Ловушка темной материи
    recipe = {"Ловушка темной материи", "Recipe_Alternate_DarkMatter_Trap", 2.0, {{"Desc_AluminumPlate_C", 1}, {"Desc_HeavyOilResidue_C", 5}}, {{"Desc_DarkMatterResidue_C", 1}}, "Ускоритель частиц"};
    gameData.addRecipe("Desc_DarkMatterResidue_C", recipe);
    
    // Альт: Мутные алмазы
    recipe = {"Мутные алмазы", "Recipe_Alternate_Diamond_Cloudy", 3.0, {{"Desc_Coal_C", 12}, {"Desc_Limestone_C", 24}}, {{"Desc_Diamonds_C", 1}}, "Ускоритель частиц"};
    gameData.addRecipe("Desc_Diamonds_C", recipe);
    
    // Альт: Нефтяные алмазы
    recipe = {"Нефтяные алмазы", "Recipe_Alternate_Diamond_OilBased", 2.0, {{"Desc_LiquidOil_C", 10}}, {{"Desc_Diamonds_C", 2}}, "Ускоритель частиц"};
    gameData.addRecipe("Desc_Diamonds_C", recipe);
    
    // Альт: Алмазы из нефтепродуктов
    recipe = {"Алмазы из нефтепродуктов", "Recipe_Alternate_Diamond_Petroleum", 2.0, {{"Desc_PetroleumCoke_C", 24}}, {{"Desc_Diamonds_C", 1}}, "Ускоритель частиц"};
    gameData.addRecipe("Desc_Diamonds_C", recipe);
    
    // Альт: Розовые алмазы
    recipe = {"Розовые алмазы", "Recipe_Alternate_Diamond_Pink", 4.0, {{"Desc_Coal_C", 8}, {"Desc_QuartzCrystal_C", 3}}, {{"Desc_Diamonds_C", 1}}, "Ускоритель частиц"};
    gameData.addRecipe("Desc_Diamonds_C", recipe);
    
    // Альт: Турбо алмазы
    recipe = {"Турбо алмазы", "Recipe_Alternate_Diamond_Turbo", 3.0, {{"Desc_Coal_C", 30}, {"Desc_TurboFuel_C", 2}}, {{"Desc_Diamonds_C", 3}}, "Ускоритель частиц"};
    gameData.addRecipe("Desc_Diamonds_C", recipe);
    
    // Альт: Темное ионизированное топливо
    recipe = {"Темное ионизированное топливо", "Recipe_Alternate_IonizedFuel_Dark", 24.0, {{"Desc_RocketFuel_C", 16}, {"Desc_DarkMatterCrystal_C", 1}}, {{"Desc_IonizedFuel_C", 20}}, "Очиститель"};
    gameData.addRecipe("Desc_IonizedFuel_C", recipe);
    
    // Альт: Нитро ракетное топливо
    recipe = {"Нитро ракетное топливо", "Recipe_Alternate_RocketFuel_Nitro", 2.4, {{"Desc_Fuel_C", 4}, {"Desc_NitrogenGas_C", 3}, {"Desc_Sulfur_C", 4}, {"Desc_Coal_C", 2}}, {{"Desc_RocketFuel_C", 6}, {"Desc_CompactedCoal_C", 1}}, "Блендер"};
    gameData.addRecipe("Desc_RocketFuel_C", recipe);
} 