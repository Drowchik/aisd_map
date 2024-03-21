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
		Pair<Key, Value> _data;
		bool is_empty;
		Node(const Pair<Key, Value>& data, bool empty = false, Node* next = nullptr) : _data(data), _next(next) {}
		Node() : _data(Pair<Key, Value>()), is_empty(true), _next(nullptr) {}
	};
	template<typename Key, typename Value>
	class Map {
		vector<Node<Key, Value>*> _data;
		size_t size_fullness;
	public:
		Map(size_t size) : _data(size) {}
	};
}