#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        // Always call the original function first
        if (!MenuLayer::init()) return false;

        log::info("Button Spawning loaded on the main menu!");

        // Create a button using a built-in GD sprite
        auto button = CCMenuItemSpriteExtra::create(
            CCSprite::createWithSpriteFrameName("GJ_likeBtn_001.png"),
            this,
            menu_selector(MyMenuLayer::onMyButton)
        );
        button->setID("spawned-button"_spr);

        // Add it to the existing bottom menu and re-layout
        if (auto menu = this->getChildByID("bottom-menu")) {
            menu->addChild(button);
            menu->updateLayout();
        }

        return true;
    }

    void onMyButton(CCObject*) {
        FLAlertLayer::create(
            "Button Spawning",
            "Hello from Penguini's mod!",
            "OK"
        )->show();
    }
};
