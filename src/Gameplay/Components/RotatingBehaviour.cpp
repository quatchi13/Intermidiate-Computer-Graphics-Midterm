#include "Gameplay/Components/RotatingBehaviour.h"

#include "Gameplay/GameObject.h"

#include "Utils/ImGuiHelper.h"
#include "Utils/JsonGlmHelpers.h"
#include "Gameplay/Components/RenderComponent.h"
#include "Gameplay/Material.h"

void RotatingBehaviour::Update(float deltaTime) {
	
}

void RotatingBehaviour::RenderImGui() {
	LABEL_LEFT(ImGui::DragFloat3, "Speed", &RotationSpeed.x);
}

nlohmann::json RotatingBehaviour::ToJson() const {
	return {
		{ "speed", RotationSpeed }
	};
}

RotatingBehaviour::Sptr RotatingBehaviour::FromJson(const nlohmann::json& data) {
	RotatingBehaviour::Sptr result = std::make_shared<RotatingBehaviour>();
	result->RotationSpeed = JsonGet(data, "speed", result->RotationSpeed);
	return result;
}
