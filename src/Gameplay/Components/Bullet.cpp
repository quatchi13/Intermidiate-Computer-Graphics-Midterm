#include "Gameplay/Components/Bullet.h"

#include "Gameplay/GameObject.h"

#include "Utils/ImGuiHelper.h"
#include "Utils/JsonGlmHelpers.h"

void Bullet::Update(float deltaTime) {
	GetGameObject()->SetPostion(GetGameObject()->GetPosition() + BulletSpeed * deltaTime);
	
}

void Bullet::RenderImGui() {
	LABEL_LEFT(ImGui::DragFloat3, "Speed", &BulletSpeed.y);
}

nlohmann::json Bullet::ToJson() const {
	return {
		{ "speed", BulletSpeed }
	};
}

Bullet::Sptr Bullet::FromJson(const nlohmann::json& data) {
	Bullet::Sptr result = std::make_shared<Bullet>();
	result->BulletSpeed = JsonGet(data, "speed", result->BulletSpeed);
	return result;
}
