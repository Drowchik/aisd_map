#pragma once
#include <iostream>
#include<vector>

using namespace std;

namespace map_realization {
	template<typename Key, typename Value> 
	struct Pair {
		Key _key;
		Value _value;
		Pair() : _key(Key()), _value(Value()) {}
		Pair(Key key, Value val) : _key(key), _value(val) {}
	};
	template<typename Key, typename Value>
	struct Node {
		Node* _next;
		Pair<Key, Value> pair_data;
		Node(const Pair<Key, Value>& data, Node* next = nullptr) : pair_data(data), _next(next) {}
		Node() : pair_data(Pair<Key, Value>()), _next(nullptr) {}
	};
	template<typename Key, typename Value>
	class Map {
		vector<Node<Key, Value>*> _data;
		size_t size_fullness;
		size_t hash_function(const Key& key) {
			const float A = 0.6128033988;
			float f = key * A - int(key * A);
			return size_t(f * _data.size());
		}
	public:
		Map(size_t size) : _data(size), size_fullness(0) {}
		~Map() {
			clear();
		}
		Map(const Map& a) : _data(a._data.size()) {
			size_t size = a._data.size();

		}
		void clear() {
			size_t size = _data.size();
			for (size_t i = 0; i < size; i++) {
				if (_data[i]) {
					Node<Key, Value>* head = _data[i];
					while (head) {
						Node<Key, Value>* temp = head;
						head=head->_next;
						delete temp;
					}
				}
			}
			_data.clear();
		}
		size_t count(const Key& key) const {
			return int(contains(key));
		}
		bool contains(const Key& key) const {
			size_t index = hash_function(key);
			if (!_data[index]) {
				return false;
			}
			Node<Key, Value>* ptr = _data[index];
			while (ptr) {
				if (ptr->pair_data._key == key) {
					return true;
				}
				ptr=ptr->_next;
			}
			return false;
		}
		Value* search(Key key) {
			size_t index = hash_function(key);
			if (!_data[index]) {
				return nullptr;
			}
			Node<Key, Value>* ptr = _data[index];
			while (ptr) {
				if (ptr->pair_data._key == key) {
					return ptr;
				}
				ptr = ptr->_next;
			}
		}
		void print() const {
			size_t size = _data.size();
			for (size_t i = 0; i < size; i++) {
				if (_data[i]) {
					auto ptr = _data[i];
					while (ptr) {
						cout << ptr->pair_data._key << " : " << ptr->pair_data._value << endl;
						ptr = ptr->_next;
					}
				}
			}
		}
		void insert(Key key, Value value) {
			if (contains(key)) {
				return;
			}
			size_t index = hash_function(key);
			if (!_data[index]) {
				_data[index] = new Node<Key, Value>(Pair<Key, Value>(key, value));
			}
			else {
				Node<Key, Value>* temp = _data[index];
				while (temp->_next) {
					temp = temp->_next;
				}
				temp->_next = new Node<Key, Value>(Pair<Key, Value>(key, value));
			}
			size_fullness++;
		}
		void insert_or_assign(const Key& key, const Value& value) {

		}

	};
}