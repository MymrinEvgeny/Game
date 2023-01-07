#include "Camera.hpp"

namespace Engine::Entities {

	// Methods
	void Camera::updateView() {
		m_view = glm::lookAt(m_position, m_position + m_front, m_up);
	}


	void Camera::updateProjection() {
		m_projection = glm::perspective(
			glm::radians(m_viewAngle), 
			-m_aspectRatio,
			0.0f, 1.0f);
	}


	// Constructors
	Camera::Camera(const glm::vec3& position) {
		Utils::Logger::log(Utils::Logger::Level::LOG, "Camera::Camera(...)");
		m_position = position;
		m_front = glm::vec3(0.0f, 0.0f, 1.0f);
		m_up = glm::vec3(0.0f, 1.0f, 0.0f);
		m_viewAngle = 45.0f;
		m_aspectRatio = 1.0f;
		updateView();
		updateProjection();
	}


	Camera::~Camera() {
		Utils::Logger::log(Utils::Logger::Level::LOG, "Camera::~Camera()");
	}


	// Methods
	glm::vec3 Camera::getPosition() const {
		return m_position;
	}


	glm::vec3 Camera::getFront() const {
		return m_front;
	}


	glm::vec3 Camera::getUp() const {
		return m_up;
	}


	glm::vec3 Camera::getRight() const {
		return glm::normalize(glm::cross(m_up, m_front));
	}


	glm::mat4 Camera::getView() const {
		return m_view;
	}


	glm::mat4 Camera::getProjection() const {
		return m_projection;
	}


	void Camera::setPosition(const glm::vec3& position) {
		m_position = position;
		updateView();
	}


	void Camera::setFront(const glm::vec3& front) {
		m_front = front;
		updateView();
	}


	void Camera::setUp(const glm::vec3& up) {
		m_up = up;
		updateView();
	}


	void Camera::setViewAngle(const float& viewAngle) {
		m_viewAngle = viewAngle;
		updateProjection();
	}


	void Camera::setAspectRatio(const float& aspectRatio) {
		m_aspectRatio = aspectRatio;
		updateProjection();
	}


	void Camera::rotate(const float& yaw = 0.0f, const float& pitch = 0.0f,
		const float& roll = 0.0f) {
	
		glm::vec3 front = glm::rotate(glm::vec3(0.0f, 0.0f, 1.0f), glm::radians(yaw), glm::vec3(0.0f, 1.0f, 0.0f));
		
		glm::vec3 right = glm::normalize(glm::cross(front, glm::vec3(0.0f, 1.0f, 0.0f)));
		front = glm::rotate(front, glm::radians(pitch), right);
		
		glm::vec3 up = glm::normalize(glm::cross(right, front));
		up = glm::rotate(up, glm::radians(-roll), front);
		
		m_front = front;
		m_up = up;
		
		updateView();

	}


}