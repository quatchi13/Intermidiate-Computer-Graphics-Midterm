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
}

void TextureChange::ColorChange(int lives)
{
	_renderer->GetMaterial()->Set("u_InvaderMaterial.selection", lives);
}
