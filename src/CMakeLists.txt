add_library(GameLogic
        Appliance.cpp
        FoodMaker.cpp
        FuelMaker.cpp
        GameEngine.cpp
        InformationPlayer.cpp
        Map.cpp
        NotEnoughMoney.cpp
        Order.cpp
        PartAssembler.cpp
        ProductionManager.cpp
        ResourceOrder.cpp
        Ship.cpp
        UrgentOrder.cpp
        Wallet.cpp
)

target_include_directories(GameLogic PUBLIC ../include)