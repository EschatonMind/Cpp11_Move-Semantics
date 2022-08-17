#include <iostream>
#include<vector>
using namespace std;


class Entity {

private:
	static const int size=100;
	int* pB{nullptr};

public:
	Entity() {
		pB = new int[size]{};
	}
		
	Entity(int k) {
		pB = new int[size]{};
		
		for (int i = 0; i < size; i++) {

			pB[i] = 7 * k;
		}
	}

	Entity(const Entity& other) {

		pB = new int [size] {};

		memcpy(pB, other.pB, size * sizeof(int));
	}

	Entity(Entity&& other) {
		cout << "Move constructor running ...";
		pB = other.pB;
		other.pB = nullptr;
	
	}

	Entity& operator=(const Entity& other) {
		pB = new int[size] {};
		memcpy(pB, other.pB, size * sizeof(int));
		return *this;
	}

	Entity& operator=(Entity&& other) {
		cout << "Move assignment running ...";
		delete[] pB;
		pB = other.pB;
		other.pB = nullptr;
		return *this;
	}
	~Entity() {
		delete[] pB;
	}

	friend ostream& operator<<(ostream& out, const Entity& entity);
};

ostream& operator<<(ostream& out, const Entity& entity) {
	out << "Hello from Entity";
	return out;
}

Entity getEntity() {
	return Entity();
}

int main() {

	vector<Entity> V;
	V.push_back(Entity());


	Entity entity;
	entity = getEntity();
	return 0;
}