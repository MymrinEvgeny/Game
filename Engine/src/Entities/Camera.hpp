#pragma once

#include "Utils/Logger.hpp"

#include <glm/vec3.hpp>
#include <glm/mat4x4.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>

namespace Engine::Entities {

	class Camera {
	private:

		// Fields
		glm::vec3 m_position;


		glm::vec3 m_front;


		glm::vec3 m_up;


		glm::mat4 m_view;


		float m_viewAngle;


		float m_aspectRatio;


		glm::mat4 m_projection;


		// Methods
		void updateView();


		void updateProjection();


	public:

		// Constructors
		Camera() = delete;


		Camera(const Camera&) = delete;


		Camera(Camera&&) = delete;


		Camera(const glm::vec3& position);


		~Camera();


		// Operators
		Camera& operator=(const Camera&) = delete;


		Camera& operator=(Camera&&) = delete;


		// Methods
		glm::vec3 getPosition() const;


		glm::vec3 getFront() const;


		glm::vec3 getUp() const;


		glm::vec3 getRight() const;


		glm::mat4 getView() const;


		glm::mat4 getProjection() const;


		void setPosition(const glm::vec3& position);


		void setFront(const glm::vec3& front);


		void setUp(const glm::vec3& up);


		void setViewAngle(const float& angle);


		void setAspectRatio(const float& aspectRatio);


		void rotate(const float& yaw, const float& pitch, const float& roll);


	};

}