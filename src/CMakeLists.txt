add_library(GameLogic
        Map.cpp
        NotEnoughMoney.cpp
        GameEngine.cpp
        Appliance.cpp
        FoodMaker.cpp
        FuelMaker.cpp
        InformationPlayer.cpp
        Order.cpp
        PartAssembler.cpp
        ProductionManager.cpp
        ResourceOrder.cpp
        Ship.cpp
        UrgentOrder.cpp
        Wallet.cpp
)
target_include_directories(GameLogic  PUBLIC ../include)
