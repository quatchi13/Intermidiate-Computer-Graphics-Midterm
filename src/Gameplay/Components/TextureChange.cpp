#include "Gameplay/Components/TextureChange.h"
#include <GLFW/glfw3.h>
#include "Gameplay/GameObject.h"
#include "Gameplay/Scene.h"
#include "Utils/ImGuiHelper.h"
#include "Gameplay/InputEngine.h"

void TextureChange::Awake()
{
	_renderer = GetComponent<RenderComponent>();
	std::cout << "TEST COMPONENT WORKING\N";
}

void TextureChange::RenderImGui() {
	LABEL_LEFT(ImGui::DragFloat, "Impulse", &test, 13.6f);
}

nlohmann::json TextureChange::ToJson() const {
	return {
		{ "test", test }
	};
}

TextureChange::TextureChange() :
	IComponent(),
	_renderer(nullptr),
	test(10.0f)
{ }

TextureChange::~TextureChange() = default;

TextureChange::Sptr TextureChange::FromJson(const nlohmann::json & blob) {
	TextureChange::Sptr result = std::make_shared<TextureChange>();
	result->test = blob["test"];
	return result;
}
float currentTime;
float maxTime = 10.0f;
void TextureChange::Update(float deltaTime)
{
	if (InputEngine::GetKeyState(GLFW_KEY_1) == ButtonState::Pressed) {
		std::cout << "1 was pressed\n";
		if (lives != 1)
		{
			lives--;
		}
		if (_renderer)
		{
			_renderer->GetMaterial()->Set("u_InvaderMaterial.selection", lives);
		}
		else
		{
			std::cout << "THERE'S NO RENDERER!\n";
		}
	}

	GetGameObject()->GetScene()->Lights[0].Position = GetGameObject()->GetPosition();
	GetGameObject()->GetScene()->SetupShaderAndLights();

	if (InputEngine::GetKeyState(GLFW_KEY_2) == ButtonState::Pressed) {
		std::cout << "2 was pressed\n";
		std::cout << GetGameObject()->GetScene()->Lights[3].Position.x << " " << GetGameObject()->GetScene()->Lights[3].Position.y << "\n";

	}

	if (InputEngine::GetKeyState(GLFW_KEY_3) == ButtonState::Pressed) {
		std::cout << "2 was pressed\n";
		GetGameObject()->GetScene()->Lights[3].Position.x += 1.0f;
		GetGameObject()->GetScene()->SetupShaderAndLights();

	}

	if (InputEngine::GetKeyState(GLFW_KEY_4) == ButtonState::Pressed)
	{
		for (int i = 0; i < 6; i++)
		{
			GetGameObject()->GetScene()->Lights[i].Range = 10;
		}
	}

	if (InputEngine::GetKeyState(GLFW_KEY_5) == ButtonState::Pressed)
	{
		for (int i = 0; i < 6; i++)
		{
			GetGameObject()->GetScene()->Lights[i].Range = 100;
		}
	}

	if (InputEngine::GetKeyState(GLFW_KEY_6) == ButtonState::Pressed)
	{
		GetGameObject()->GetScene()->Lights[6].Position.x += 10;
	}

	if (currentTime <= maxTime)
	{
		currentTime += deltaTime;
		float t = currentTime / maxTime;
		glm::vec3 test = lerp(glm::vec3(-40.f, 0.f, 3.f), glm::vec3(40.f, 0.f, 3.0f), t);
		std::cout << test.x << " " << test.y << " " << test.z << "\n";
		GetGameObject()->GetScene()->Lights[6].Position = test;
	}
	else
	{
		currentTime = 0.f;
	}
	
}

void TextureChange::ColorChange(int lives)
{
	_renderer->GetMaterial()->Set("u_InvaderMaterial.selection", lives);
}

void TextureChange::Damage()
{
	if (lives > 1)
	{
		lives--;
		_renderer->GetMaterial()->Set("u_InvaderMaterial.selection", lives);
	}
	else
	{
		GetGameObject()->SetPostion(glm::vec3(100, 100, 100));


	}
}


