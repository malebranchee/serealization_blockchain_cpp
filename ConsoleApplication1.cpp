#include <iostream>
#include <vector>
#include <string>

namespace EventSystem
{


	class System {
	private:
		std::string name;
		int32_t descriptor;
		int16_t index;
		bool active;
		std::vector<Event*> events;
	public:
		System(std::string);
		~System();
	public:
		void addEvent(Event*);
		Event* getEvent();
		bool isActive();
	};

	class Event {
	public:
		enum class DeviceType : int8_t{
			KEYBOARD = 1,
			MOUSE,
			TOUCHPAD,
			JOYSTICK
		};
		DeviceType dType;
		System* system;
	public:
		Event(DeviceType);
		DeviceType getdType();
		friend std::ostream& operator<<(std::ostream& stream, const DeviceType dType) {
			std::string result;
#define PRINT(a) result = #a;
			switch (dType) {
				case KEYBOARD: PRINT(KEYBOARD); break;
				case MOUSE: PRINT(MOUSE); break;
				case TOUCHPAD: PRINT(TOUCHPAD); break;
				case JOYSTICK: PRINT(JOYSTICK); break;


			}
			return stream << result;
		}
		void bind(System*, Event*);

	};



	class KeyboardEvent : public Event {
		private:
			int16_t keycode;
			bool pressed;
			bool released;
		public:
			KeyboardEvent(int16_t, bool, bool);

	};

	System::System(std::string name)
		:
		name(name),
		descriptor(123),
		index(1),
		active(true) {}

	System::~System() 
	{
		//TODO::
	}

	void System::addEvent(Event* e)
	{
		e->bind(this, e);
	}
	
	Event* System::getEvent() {
		return events.front();
	}

	bool System::isActive()
	{
		bool flag = system ? true : false;
		return flag;
	}

}




int main()
{



	return 0;
}