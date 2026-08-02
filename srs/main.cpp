#include <Geode/Geode.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(StereoMadnessPlayLayer, PlayLayer) {
    bool init(GJGameLevel* level, bool useReplay, bool dontCreateObjects) {
        if (!PlayLayer::init(level, useReplay, dontCreateObjects))
            return false;

        if (!level || !Mod::get()->getSettingValue<bool>("enabled"))
            return true;

        auto const& name = level->m_levelName;
        if (name == "Stereo Madness") {
            auto duration = Mod::get()->getSettingValue<double>("duration");
            Notification::create(
                "Stereo Madness: удачного прохождения!",
                NotificationIcon::Info,
                static_cast<float>(duration)
            )->show();
        }

        return true;
    }
};
