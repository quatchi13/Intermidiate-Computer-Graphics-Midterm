#pragma once
#include "IComponent.h"

/// <summary>
/// Showcases a very simple behaviour that rotates the parent gameobject at a fixed rate over time
/// </summary>
class Bullet : public Gameplay::IComponent {
public:
	typedef std::shared_ptr<Bullet> Sptr;

	Bullet() = default;
	glm::vec3 BulletSpeed;

	virtual void Update(float deltaTime) override;

	virtual void RenderImGui() override;

	virtual nlohmann::json ToJson() const override;
	static Bullet::Sptr FromJson(const nlohmann::json& data);

	MAKE_TYPENAME(Bullet);
};

