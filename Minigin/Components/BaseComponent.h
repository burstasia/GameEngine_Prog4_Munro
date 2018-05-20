#pragma once


namespace dae
{
	class GameObject;
	class Level;
	class TransformComponent;

	class BaseComponent
	{
	public:
		BaseComponent(void);
		virtual ~BaseComponent(void);

		GameObject* GetGameObject() const;
		TransformComponent* GetTransform() const;

	protected:
		virtual void Init() = 0;
		virtual void Update(float elapsedSec) = 0;
		virtual void Render() = 0;

		GameObject* m_pGameObject;

	private:
		friend class GameObject;
		friend class Level;
	};
}


