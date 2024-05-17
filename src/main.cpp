#include "Geode/modify/PlayLayer.hpp"
#include "Geode/modify/PlayerObject.hpp"
#include <Geode/Geode.hpp>
#include <Geode/modify/Modify.hpp>

using namespace geode::prelude;

struct Owo : Modify<Owo, PlayLayer> {
  void postUpdate(float p0) {
    PlayLayer::postUpdate(p0);

    bool enabled = Mod::get()->getSettingValue<bool>("enabled");

    if (enabled) {
      this->m_player1->setRotation(0.f);
      this->m_player2->setRotation(0.f);
    }
  }
};
