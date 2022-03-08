#include "Gameplay/Components/Move.h"

#include "Gameplay/GameObject.h"

#include "Utils/ImGuiHelper.h"
#include "Utils/JsonGlmHelpers.h"
#include "Gameplay/InputEngine.h"

void Move::Update(float deltaTime) {
	
	if (InputEngine::GetKeyState(GLFW_KEY_LEFT) == ButtonState::Down) {
		GetGameObject()->SetPostion(GetGameObject()->GetPosition() - MoveSpeed * deltaTime);
	}

	if (InputEngine::GetKeyState(GLFW_KEY_RIGHT) == ButtonState::Down) {
		GetGameObject()->SetPostion(GetGameObject()->GetPosition() + MoveSpeed * deltaTime);
	}
	
	if (count < 8)
	{
		if (InputEngine::GetKeyState(GLFW_KEY_SPACE) == ButtonState::Pressed) {
			GetGameObject()->GetChildren()[0]->SetPostion(glm::vec3(0, 3, 0));
			count++;
		}
	}
}

void Move::RenderImGui() {
	LABEL_LEFT(ImGui::DragFloat3, "Speed", &MoveSpeed.x);
}

nlohmann::json Move::ToJson() const {
	return {
		{ "speed", MoveSpeed }
	};
}

Move::Sptr Move::FromJson(const nlohmann::json& data) {
	Move::Sptr result = std::make_shared<Move>();
	result->MoveSpeed = JsonGet(data, "speed", result->MoveSpeed);
	return result;
}
