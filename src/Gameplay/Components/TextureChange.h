#pragma once
#include "IComponent.h"
#include "Gameplay/Physics/RigidBody.h"
#include "Gameplay/Components/RenderComponent.h"

class TextureChange : public Gameplay::IComponent {
public:
	typedef std::shared_ptr<TextureChange> Sptr;

	std::weak_ptr<Gameplay::IComponent> Panel;

	TextureChange();
	virtual ~TextureChange();

	virtual void Awake() override;
	virtual void Update(float deltaTime) override;
	void ColorChange(int lives);

public:
	virtual void RenderImGui() override;
	MAKE_TYPENAME(TextureChange);
	virtual nlohmann::json ToJson() const override;
	static TextureChange::Sptr FromJson(const nlohmann::json& blob);

protected:
	float test;
	int lives = 6;
	RenderComponent::Sptr _renderer;
};