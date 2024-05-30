#include "Geode/loader/Mod.hpp"
#include <Geode/Geode.hpp>
#include <Geode/modify/Modify.hpp>
#include <Geode/modify/PlayLayer.hpp>

using namespace geode::prelude;

class $modify(PlayLayer) {
  void postUpdate(float p0) {
    PlayLayer::postUpdate(p0);

    bool enabled = Mod::get()->getSettingValue<bool>("enabled");
    bool no_anim = Mod::get()->getSettingValue<bool>("no-anim");
    float rotdeg = Mod::get()->getSettingValue<double>("rotdeg");

    if (enabled) {
      this->m_player1->setRotation(rotdeg);
      this->m_player2->setRotation(rotdeg);

      if (no_anim) {
        if (this->m_player1->m_isRobot) {
          this->m_player1->updatePlayerRobotFrame(0);
        }

        if (this->m_player2->m_isRobot) {
          this->m_player2->updatePlayerRobotFrame(0);
        }

        if (this->m_player1->m_isSpider) {
          this->m_player1->updatePlayerSpiderFrame(0);
        }

        if (this->m_player2->m_isSpider) {
          this->m_player2->updatePlayerSpiderFrame(0);
        }
      }
    }
  }
};
