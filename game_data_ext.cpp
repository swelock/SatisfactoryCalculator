#include "game_data_ext.h"

void populateAlternateRecipes(GameData& gameData)
{
    GameRecipe recipe;

    // --- ALTERNATE INGOTS ---
    // Solid Steel Ingot (Alternate)
    recipe = {"Цельный стальной слиток", "Recipe_Alternate_IngotSteel_1", 3.0, {{"Desc_IronIngot_C", 2}, {"Desc_Coal_C", 2}}, {{"Desc_SteelIngot_C", 3}}, "Литейная"};
    gameData.addRecipe("Desc_SteelIngot_C", recipe);

    // Coke Steel Ingot (Alternate)
    recipe = {"Коксовый стальной слиток", "Recipe_Alternate_IngotSteel_2", 12.0, {{"Desc_IronOre_C", 15}, {"Desc_PetroleumCoke_C", 15}}, {{"Desc_SteelIngot_C", 20}}, "Литейная"};
    gameData.addRecipe("Desc_SteelIngot_C", recipe);

    // Pure Iron Ingot (Alternate)
    recipe = {"Чистый железный слиток", "Recipe_Alternate_IngotIron", 12.0, {{"Desc_IronOre_C", 7}, {"Desc_Water_C", 4}}, {{"Desc_IronIngot_C", 13}}, "Очиститель"};
    gameData.addRecipe("Desc_IronIngot_C", recipe);

    // --- ALTERNATE BASIC PARTS ---
    // Steel Screw (Alternate)
    recipe = {"Винт из стали", "Recipe_Alternate_Screw", 2.4, {{"Desc_SteelBeam_C", 1}}, {{"Desc_Screw_C", 52}}, "Конструктор"};
    gameData.addRecipe("Desc_Screw_C", recipe);

    // Cast Screw (Alternate) 
    recipe = {"Литой винт", "Recipe_Alternate_Screw_2", 24.0, {{"Desc_IronIngot_C", 12}}, {{"Desc_Screw_C", 50}}, "Конструктор"};
    gameData.addRecipe("Desc_Screw_C", recipe);

    // Stitched Iron Plate (Alternate)
    recipe = {"Прошитая железная пластина", "Recipe_Alternate_ReinforcedIronPlate_1", 24.0, {{"Desc_IronPlate_C", 10}, {"Desc_Wire_C", 20}}, {{"Desc_ReinforcedIronPlate_C", 3}}, "Сборщик"};
    gameData.addRecipe("Desc_ReinforcedIronPlate_C", recipe);

    // Bolted Iron Plate (Alternate)
    recipe = {"Болтовая железная пластина", "Recipe_Alternate_ReinforcedIronPlate_2", 12.0, {{"Desc_IronPlate_C", 18}, {"Desc_Screw_C", 50}}, {{"Desc_ReinforcedIronPlate_C", 3}}, "Сборщик"};
    gameData.addRecipe("Desc_ReinforcedIronPlate_C", recipe);

    // Fused Wire (Alternate)
    recipe = {"Плавленая проволока", "Recipe_Alternate_Wire_1", 20.0, {{"Desc_CopperIngot_C", 4}, {"Desc_CateriumIngot_C", 1}}, {{"Desc_Wire_C", 30}}, "Конструктор"};
    gameData.addRecipe("Desc_Wire_C", recipe);

    // Iron Wire (Alternate)
    recipe = {"Железная проволока", "Recipe_Alternate_Wire_2", 24.0, {{"Desc_IronIngot_C", 5}}, {{"Desc_Wire_C", 9}}, "Конструктор"};
    gameData.addRecipe("Desc_Wire_C", recipe);

    // Insulated Cable (Alternate)
    recipe = {"Изолированный кабель", "Recipe_Alternate_Cable_1", 12.0, {{"Desc_Wire_C", 9}, {"Desc_Rubber_C", 6}}, {{"Desc_Cable_C", 20}}, "Сборщик"};
    gameData.addRecipe("Desc_Cable_C", recipe);

    // Quickwire Cable (Alternate)
    recipe = {"Кабель из быстрой проволоки", "Recipe_Alternate_Cable_2", 24.0, {{"Desc_Quickwire_C", 3}, {"Desc_Rubber_C", 2}}, {{"Desc_Cable_C", 11}}, "Сборщик"};
    gameData.addRecipe("Desc_Cable_C", recipe);

    // Caterium Quickwire (Alternate)
    recipe = {"Катериевая быстрая проволока", "Recipe_Alternate_Quickwire", 8.0, {{"Desc_CateriumIngot_C", 1}, {"Desc_CopperIngot_C", 5}}, {{"Desc_Quickwire_C", 12}}, "Сборщик"};
    gameData.addRecipe("Desc_Quickwire_C", recipe);

    // --- ALTERNATE ADVANCED PARTS ---
    // Steel Rotor (Alternate)
    recipe = {"Стальной ротор", "Recipe_Alternate_Rotor", 12.0, {{"Desc_SteelPipe_C", 2}, {"Desc_Wire_C", 6}}, {{"Desc_Rotor_C", 1}}, "Сборщик"};
    gameData.addRecipe("Desc_Rotor_C", recipe);

    // Copper Rotor (Alternate)
    recipe = {"Медный ротор", "Recipe_Alternate_Rotor_2", 16.0, {{"Desc_CopperSheet_C", 6}, {"Desc_Screw_C", 52}}, {{"Desc_Rotor_C", 3}}, "Сборщик"};
    gameData.addRecipe("Desc_Rotor_C", recipe);

    // Quickwire Stator (Alternate)
    recipe = {"Статор из быстрой проволоки", "Recipe_Alternate_Stator", 15.0, {{"Desc_SteelPipe_C", 4}, {"Desc_Quickwire_C", 15}}, {{"Desc_Stator_C", 2}}, "Сборщик"};
    gameData.addRecipe("Desc_Stator_C", recipe);

    // Steeled Frame (Alternate)
    recipe = {"Стальной каркас", "Recipe_Alternate_ModularFrame", 60.0, {{"Desc_ReinforcedIronPlate_C", 2}, {"Desc_SteelPipe_C", 10}}, {{"Desc_ModularFrame_C", 3}}, "Сборщик"};
    gameData.addRecipe("Desc_ModularFrame_C", recipe);

    // Encased Industrial Pipe (Alternate)
    recipe = {"Железобетонная труба", "Recipe_Alternate_EncasedIndustrialBeam", 15.0, {{"Desc_SteelPipe_C", 7}, {"Desc_Concrete_C", 5}}, {{"Desc_EncasedIndustrialBeam_C", 1}}, "Сборщик"};
    gameData.addRecipe("Desc_EncasedIndustrialBeam_C", recipe);

    // Rigour Motor (Alternate)
    recipe = {"Жесткий мотор", "Recipe_Alternate_Motor_1", 48.0, {{"Desc_Rotor_C", 3}, {"Desc_Stator_C", 3}, {"Desc_CrystalOscillator_C", 1}}, {{"Desc_Motor_C", 6}}, "Производитель"};
    gameData.addRecipe("Desc_Motor_C", recipe);

    // Silicon Circuit Board (Alternate)
    recipe = {"Кремниевая микросхема", "Recipe_Alternate_CircuitBoard_1", 24.0, {{"Desc_CopperSheet_C", 11}, {"Desc_Silica_C", 11}}, {{"Desc_CircuitBoard_C", 5}}, "Сборщик"};
    gameData.addRecipe("Desc_CircuitBoard_C", recipe);

    // Caterium Circuit Board (Alternate)
    recipe = {"Катериевая микросхема", "Recipe_Alternate_CircuitBoard_2", 48.0, {{"Desc_Plastic_C", 12}, {"Desc_Quickwire_C", 30}}, {{"Desc_CircuitBoard_C", 8}}, "Сборщик"};
    gameData.addRecipe("Desc_CircuitBoard_C", recipe);

    // Crystal Computer (Alternate)
    recipe = {"Кристаллический компьютер", "Recipe_Alternate_Computer_1", 64.0, {{"Desc_CircuitBoard_C", 8}, {"Desc_CrystalOscillator_C", 3}}, {{"Desc_Computer_C", 3}}, "Сборщик"};
    gameData.addRecipe("Desc_Computer_C", recipe);

    // Caterium Computer (Alternate)
    recipe = {"Катериевый компьютер", "Recipe_Alternate_Computer_2", 16.0, {{"Desc_CircuitBoard_C", 7}, {"Desc_Quickwire_C", 28}}, {{"Desc_Computer_C", 1}}, "Производитель"};
    gameData.addRecipe("Desc_Computer_C", recipe);

    // Heavy Encased Frame (Alternate)
    recipe = {"Тяжелый железобетонный каркас", "Recipe_Alternate_ModularFrameHeavy", 64.0, {{"Desc_ModularFrame_C", 8}, {"Desc_EncasedIndustrialBeam_C", 10}, {"Desc_SteelPipe_C", 36}, {"Desc_Concrete_C", 22}}, {{"Desc_ModularFrameHeavy_C", 3}}, "Производитель"};
    gameData.addRecipe("Desc_ModularFrameHeavy_C", recipe);

    // Electric Motor (Alternate)
    recipe = {"Электрический мотор", "Recipe_Alternate_Motor_2", 16.0, {{"Desc_ElectromagneticControlRod_C", 1}, {"Desc_Rotor_C", 2}}, {{"Desc_Motor_C", 2}}, "Сборщик"};
    gameData.addRecipe("Desc_Motor_C", recipe);

    // Turbo Electric Motor (Alternate)
    recipe = {"Турбо электрический мотор", "Recipe_Alternate_TurboMotor_1", 64.0, {{"Desc_Motor_C", 7}, {"Desc_RadioControlUnit_C", 9}, {"Desc_ElectromagneticControlRod_C", 5}, {"Desc_Rotor_C", 7}}, {{"Desc_MotorLightweight_C", 3}}, "Производитель"};
    gameData.addRecipe("Desc_MotorLightweight_C", recipe);

    // --- ALTERNATE FLUIDS/MATERIALS ---
    // Recycled Plastic (Alternate)
    recipe = {"Переработанный пластик", "Recipe_Alternate_Plastic_1", 12.0, {{"Desc_Rubber_C", 6}, {"Desc_HeavyOilResidue_C", 6}}, {{"Desc_Plastic_C", 12}}, "Очиститель"};
    gameData.addRecipe("Desc_Plastic_C", recipe);

    // Recycled Rubber (Alternate)
    recipe = {"Переработанная резина", "Recipe_Alternate_Rubber_1", 12.0, {{"Desc_Plastic_C", 6}, {"Desc_HeavyOilResidue_C", 6}}, {{"Desc_Rubber_C", 12}}, "Очиститель"};
    gameData.addRecipe("Desc_Rubber_C", recipe);

    // Wet Concrete (Alternate)
    recipe = {"Мокрый бетон", "Recipe_Alternate_Concrete", 3.0, {{"Desc_Limestone_C", 6}, {"Desc_Water_C", 5}}, {{"Desc_Concrete_C", 4}}, "Очиститель"};
    gameData.addRecipe("Desc_Concrete_C", recipe);

    // Fine Concrete (Alternate)
    recipe = {"Мелкий бетон", "Recipe_Alternate_Concrete_2", 12.0, {{"Desc_Silica_C", 3}, {"Desc_Limestone_C", 12}}, {{"Desc_Concrete_C", 10}}, "Сборщик"};
    gameData.addRecipe("Desc_Concrete_C", recipe);

    // УДАЛЕНО: Charcoal и Biocoal альтернативы - они неэффективны для автоматизации
    // и вызывают появление древесины в производственных цепочках

    // Cheap Silica (Alternate)
    recipe = {"Дешевый кремнезем", "Recipe_Alternate_Silica", 16.0, {{"Desc_RawQuartz_C", 3}, {"Desc_Limestone_C", 5}}, {{"Desc_Silica_C", 7}}, "Сборщик"};
    gameData.addRecipe("Desc_Silica_C", recipe);

    // Turbofuel (Alternate)
    recipe = {"Турботопливо", "Recipe_Alternate_Turbofuel", 16.0, {{"Desc_Fuel_C", 6}, {"Desc_CompactedCoal_C", 4}}, {{"Desc_TurboFuel_C", 5}}, "Очиститель"};
    gameData.addRecipe("Desc_TurboFuel_C", recipe);

    // Add items for new alternate recipes
    gameData.addRecipe("Desc_PetroleumCoke_C", {"Нефтяной кокс", "Recipe_PetroleumCoke_C", 6.0, {{"Desc_HeavyOilResidue_C", 4}}, {{"Desc_PetroleumCoke_C", 12}}, "Очиститель"});
    gameData.addRecipe("Desc_Water_C", {"Вода", "Recipe_Water_C", 0.0, {}, {{"Desc_Water_C", 120}}, "Водозабор"});
    gameData.addRecipe("Desc_HeavyOilResidue_C", {"Тяжелые нефтяные остатки", "Recipe_HeavyOilResidue_C", 6.0, {{"Desc_LiquidOil_C", 3}}, {{"Desc_HeavyOilResidue_C", 4}, {"Desc_Polymer_C", 2}}, "Очиститель"});
}

void populateHubRequirements(GameData& gameData)
{
    // === TIER 0 - Onboarding ===
    // HUB Upgrade 1
    gameData.addHubRequirement(1, {{"Desc_IronRod_C", 10}});
    
    // HUB Upgrade 2  
    gameData.addHubRequirement(2, {{"Desc_IronRod_C", 20}, {"Desc_IronPlate_C", 10}});
    
    // HUB Upgrade 3
    gameData.addHubRequirement(3, {{"Desc_IronRod_C", 20}, {"Desc_IronPlate_C", 20}, {"Desc_Wire_C", 20}});
    
    // HUB Upgrade 4
    gameData.addHubRequirement(4, {{"Desc_IronPlate_C", 75}, {"Desc_Cable_C", 20}, {"Desc_Concrete_C", 10}});
    
    // HUB Upgrade 5
    gameData.addHubRequirement(5, {{"Desc_IronRod_C", 75}, {"Desc_Cable_C", 50}, {"Desc_Concrete_C", 20}});
    
    // HUB Upgrade 6 (Space Elevator)
    gameData.addHubRequirement(6, {{"Desc_IronRod_C", 100}, {"Desc_IronPlate_C", 100}, {"Desc_Wire_C", 100}, {"Desc_Concrete_C", 50}});

    // === TIER 1 ===
    // Base Building
    gameData.addHubRequirement(11, {{"Desc_Concrete_C", 200}, {"Desc_IronPlate_C", 100}, {"Desc_IronRod_C", 100}});
    
    // Logistics 
    gameData.addHubRequirement(12, {{"Desc_IronPlate_C", 150}, {"Desc_IronRod_C", 150}, {"Desc_Wire_C", 300}});
    
    // Field Research
    gameData.addHubRequirement(13, {{"Desc_Wire_C", 300}, {"Desc_Screw_C", 300}, {"Desc_IronPlate_C", 100}});

    // === TIER 2 ===
    // Part Assembly
    gameData.addHubRequirement(21, {{"Desc_Cable_C", 200}, {"Desc_IronRod_C", 200}, {"Desc_Screw_C", 500}, {"Desc_IronPlate_C", 300}});
    
    // Obstacle Clearing
    gameData.addHubRequirement(22, {{"Desc_Screw_C", 500}, {"Desc_Cable_C", 100}, {"Desc_Concrete_C", 100}});
    
    // Jump Pads
    gameData.addHubRequirement(23, {{"Desc_Rotor_C", 50}, {"Desc_IronPlate_C", 300}, {"Desc_Cable_C", 150}});
    
    // Resource Sink Bonus Program
    gameData.addHubRequirement(24, {{"Desc_Concrete_C", 400}, {"Desc_Wire_C", 500}, {"Desc_IronRod_C", 200}, {"Desc_IronPlate_C", 200}});
    
    // Logistics Mk.2
    gameData.addHubRequirement(25, {{"Desc_ReinforcedIronPlate_C", 50}, {"Desc_Concrete_C", 200}, {"Desc_IronRod_C", 300}, {"Desc_IronPlate_C", 300}});

    // === TIER 3 ===
    // Coal Power (requires Space Elevator Phase 1)
    gameData.addHubRequirement(31, {{"Desc_ReinforcedIronPlate_C", 150}, {"Desc_Rotor_C", 50}, {"Desc_Cable_C", 300}});
    
    // Vehicular Transport
    gameData.addHubRequirement(32, {{"Desc_ModularFrame_C", 25}, {"Desc_Rotor_C", 100}, {"Desc_Cable_C", 200}, {"Desc_IronPlate_C", 400}});
    
    // Basic Steel Production
    gameData.addHubRequirement(33, {{"Desc_ModularFrame_C", 50}, {"Desc_Rotor_C", 150}, {"Desc_Concrete_C", 500}, {"Desc_Wire_C", 1000}});
    
    // Enhanced Asset Security
    gameData.addHubRequirement(34, {{"Desc_ReinforcedIronPlate_C", 100}, {"Desc_IronRod_C", 600}, {"Desc_Wire_C", 1500}});

    // === TIER 4 ===
    // FICSIT Blueprints
    gameData.addHubRequirement(41, {{"Desc_ModularFrame_C", 100}, {"Desc_SteelBeam_C", 200}, {"Desc_Cable_C", 500}, {"Desc_Concrete_C", 1000}});
    
    // Logistics Mk.3
    gameData.addHubRequirement(42, {{"Desc_SteelBeam_C", 200}, {"Desc_SteelPipe_C", 200}, {"Desc_ReinforcedIronPlate_C", 400}});
    
    // Advanced Steel Production
    gameData.addHubRequirement(43, {{"Desc_SteelPipe_C", 100}, {"Desc_ModularFrame_C", 100}, {"Desc_Stator_C", 200}, {"Desc_Concrete_C", 500}});
    
    // Expanded Power Infrastructure
    gameData.addHubRequirement(44, {{"Desc_EncasedIndustrialBeam_C", 50}, {"Desc_SteelBeam_C", 100}, {"Desc_ModularFrame_C", 200}, {"Desc_Wire_C", 2000}});
    
    // Hypertubes
    gameData.addHubRequirement(45, {{"Desc_EncasedIndustrialBeam_C", 50}, {"Desc_SteelPipe_C", 300}, {"Desc_CopperSheet_C", 500}});

    // === TIER 5 (requires Space Elevator Phase 2) ===
    // Jetpack
    gameData.addHubRequirement(51, {{"Desc_Motor_C", 50}, {"Desc_Cable_C", 1000}, {"Desc_IronPlate_C", 1000}});
    
    // Oil Processing
    gameData.addHubRequirement(52, {{"Desc_Motor_C", 50}, {"Desc_EncasedIndustrialBeam_C", 100}, {"Desc_SteelPipe_C", 500}, {"Desc_CopperSheet_C", 500}});
    
    // Logistics Mk.4
    gameData.addHubRequirement(53, {{"Desc_Rubber_C", 200}, {"Desc_EncasedIndustrialBeam_C", 300}, {"Desc_ModularFrame_C", 400}});
    
    // Fluid Packaging
    gameData.addHubRequirement(54, {{"Desc_Plastic_C", 200}, {"Desc_SteelBeam_C", 400}, {"Desc_CopperSheet_C", 1000}});
    
    // Petroleum Power
    gameData.addHubRequirement(55, {{"Desc_Motor_C", 100}, {"Desc_EncasedIndustrialBeam_C", 100}, {"Desc_Rubber_C", 200}, {"Desc_Plastic_C", 200}});

    // === TIER 6 ===
    // Industrial Manufacturing
    gameData.addHubRequirement(61, {{"Desc_Motor_C", 200}, {"Desc_ModularFrame_C", 200}, {"Desc_Plastic_C", 400}, {"Desc_Cable_C", 1000}});
    
    // Monorail Train Technology
    gameData.addHubRequirement(62, {{"Desc_Motor_C", 250}, {"Desc_EncasedIndustrialBeam_C", 500}, {"Desc_SteelBeam_C", 1000}, {"Desc_SteelPipe_C", 1000}});
    
    // Railway Signaling
    gameData.addHubRequirement(63, {{"Desc_Computer_C", 50}, {"Desc_SteelPipe_C", 400}, {"Desc_CopperSheet_C", 1000}});
    
    // Pipeline Engineering Mk.2
    gameData.addHubRequirement(64, {{"Desc_ModularFrameHeavy_C", 50}, {"Desc_Plastic_C", 1000}, {"Desc_Rubber_C", 1000}});
    
    // FICSIT Blueprints Mk.2
    gameData.addHubRequirement(65, {{"Desc_ModularFrameHeavy_C", 100}, {"Desc_Computer_C", 100}, {"Desc_Rubber_C", 400}, {"Desc_Concrete_C", 1500}});

    // === TIER 7 (requires Space Elevator Phase 3) ===
    // Bauxite Refinement
    gameData.addHubRequirement(71, {{"Desc_Computer_C", 100}, {"Desc_ModularFrameHeavy_C", 100}, {"Desc_Motor_C", 250}, {"Desc_Rubber_C", 500}});
    
    // Hoverpack
    gameData.addHubRequirement(72, {{"Desc_AlcladAluminumSheet_C", 100}, {"Desc_ModularFrameHeavy_C", 100}, {"Desc_Computer_C", 100}, {"Desc_Motor_C", 250}});
    
    // Logistics Mk.5
    gameData.addHubRequirement(73, {{"Desc_AlcladAluminumSheet_C", 200}, {"Desc_EncasedIndustrialBeam_C", 400}, {"Desc_ReinforcedIronPlate_C", 600}});
    
    // Hazmat Suit
    gameData.addHubRequirement(74, {{"Desc_GasFilter_C", 50}, {"Desc_AluminumCasing_C", 100}, {"Desc_Quickwire_C", 500}});
    
    // Control System Development
    gameData.addHubRequirement(75, {{"Desc_AlcladAluminumSheet_C", 200}, {"Desc_AluminumCasing_C", 400}, {"Desc_Computer_C", 200}, {"Desc_Plastic_C", 1000}});

    // === TIER 8 ===
    // Aeronautical Engineering
    gameData.addHubRequirement(81, {{"Desc_RadioControlUnit_C", 50}, {"Desc_AlcladAluminumSheet_C", 100}, {"Desc_AluminumCasing_C", 200}, {"Desc_Motor_C", 300}});
    
    // Nuclear Power
    gameData.addHubRequirement(82, {{"Desc_Computer_C", 50}, {"Desc_ModularFrameHeavy_C", 200}, {"Desc_Cable_C", 1000}, {"Desc_Concrete_C", 2000}});
    
    // Advanced Aluminum Production
    gameData.addHubRequirement(83, {{"Desc_RadioControlUnit_C", 50}, {"Desc_AluminumCasing_C", 200}, {"Desc_AlcladAluminumSheet_C", 400}, {"Desc_Wire_C", 3000}});
    
    // Leading Edge Production
    gameData.addHubRequirement(84, {{"Desc_FusedModularFrame_C", 50}, {"Desc_Computer_C", 100}, {"Desc_SteelPipe_C", 1000}});
    
    // Particle Enrichment
    gameData.addHubRequirement(85, {{"Desc_MotorLightweight_C", 50}, {"Desc_FusedModularFrame_C", 100}, {"Desc_CoolingSystem_C", 200}, {"Desc_Quickwire_C", 2500}});

    // === TIER 9 (requires Space Elevator Phase 4) ===
    // Matter Conversion
    gameData.addHubRequirement(91, {{"Desc_FusedModularFrame_C", 100}, {"Desc_RadioControlUnit_C", 250}, {"Desc_CoolingSystem_C", 500}});
    
    // Quantum Encoding
    gameData.addHubRequirement(92, {{"Desc_TimeCrystal_C", 50}, {"Desc_FicsiteTrigon_C", 100}, {"Desc_MotorLightweight_C", 200}, {"Desc_Computer_C", 400}});
    
    // FICSIT Blueprint Mk.3
    gameData.addHubRequirement(93, {{"Desc_NeuralQuantumProcessor_C", 100}, {"Desc_TimeCrystal_C", 250}, {"Desc_FicsiteTrigon_C", 500}, {"Desc_FusedModularFrame_C", 500}});
    
    // Spatial Energy Regulation
    gameData.addHubRequirement(94, {{"Desc_SuperpositionOscillator_C", 100}, {"Desc_MotorLightweight_C", 250}, {"Desc_RadioControlUnit_C", 500}, {"Desc_SAMFluctuator_C", 1000}});
    
    // Peak Efficiency
    gameData.addHubRequirement(95, {{"Desc_TimeCrystal_C", 250}, {"Desc_FicsiteTrigon_C", 250}, {"Desc_AlcladAluminumSheet_C", 5000}, {"Desc_IronPlate_C", 10000}});
}

void populateElevatorRequirements(GameData& gameData)
{
    // Phase 1 - Distribution Platform
    gameData.addElevatorRequirement(1, {{"Desc_SpaceElevatorPart_1_C", 50}});
    
    // Phase 2 - Construction Dock  
    gameData.addElevatorRequirement(2, {{"Desc_SpaceElevatorPart_1_C", 1000}, {"Desc_SpaceElevatorPart_2_C", 1000}, {"Desc_SpaceElevatorPart_3_C", 100}});
    
    // Phase 3 - Main Body
    gameData.addElevatorRequirement(3, {{"Desc_SpaceElevatorPart_2_C", 2500}, {"Desc_SpaceElevatorPart_4_C", 500}, {"Desc_AdaptiveControlUnit_C", 100}});
    
    // Phase 4 - Propulsion Systems  
    gameData.addElevatorRequirement(4, {{"Desc_AssemblyDirectorSystem_C", 500}, {"Desc_MagneticFieldGenerator_C", 500}, {"Desc_ThermalPropulsionRocket_C", 250}, {"Desc_NuclearPasta_C", 100}});
    
    // Phase 5 - Assembly
    gameData.addElevatorRequirement(5, {{"Desc_NuclearPasta_C", 1000}, {"Desc_BiochemicalSculptor_C", 1000}, {"Desc_AIExpansionServer_C", 256}, {"Desc_BallisticWarpDrive_C", 200}});
} 