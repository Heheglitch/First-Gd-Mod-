#include <Geode/Geode.hpp>
#include <Geode/modify/MenuLayer.hpp>

using namespace geode::prelude;

class $modify(MyMenuLayer, MenuLayer) {
    bool init() {
        if (!MenuLayer::init()) return false;

        auto button = CCMenuItemSpriteExtra::create(
            CCSprite::createWithSpriteFrameName("GJ_likeBtn_001.png"),
            this,
            menu_selector(MyMenuLayer::onMyButton)
        );
        button->setID("spawned-button"_spr);

        // Our own menu in the top-right corner
        auto winSize = CCDirector::get()->getWinSize();
        button->setPosition({winSize.width - 40.f, winSize.height - 40.f});

        auto menu = CCMenu::create();
        menu->setID("spawned-menu"_spr);
        menu->setPosition({0.f, 0.f});
        menu->addChild(button);
        this->addChild(menu);

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
