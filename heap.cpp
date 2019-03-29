#include<iostream>

using namespace std; 

struct PLAYER {
	int pid, power, loc, cur_club; 
	int hopelist[11]; 
};

template<class T>
struct heap {
	int sz;
	T *arr;
	heap() {
		sz = 0;
		arr = new T[1001];
	}
	void push(T &a) {
		arr[++sz] = a;   // 0num  (x)  -> 1 (num)     
		upheap();
	}

	void upheap() {  // heapify -> up 
		int cur = sz;
		while (cur / 2 >= 1 && cmpFunc(arr[cur], arr[cur / 2])) {
			SWAP(arr[cur], arr[cur / 2]);
			cur /= 2;
		}
	}
	void pop() {
		arr[1] = arr[sz--]; 
		downheap(); 
	}

	void downheap() {
		int cur = 1; 
		while (cur * 2 <= sz) {
			int target = cur * 2; 
			if (target + 1 <= sz && cmpFunc(arr[target + 1], arr[target])) 
				target++; 
			if (cmpFunc(arr[target], arr[cur])) {
				SWAP(arr[target], arr[cur]); 
			}
			else
				break; 
			cur *= 2; 
		}

	}
	bool cmpFunc(PLAYER &a, PLAYER &b) {
		if (a.power < b.power) return true; 
		else if (a.power == b.power) {
			if (a.pid > b.pid) return true; 
		}
		return false; 
	}
	void size() {
		return sz; 
	}

	T& top() {
		return arr[1]; 
	}

	void clear() {
		sz = 0; 
	}
	void SWAP(T &a, T &b) {
		T t = a; 
		a = b; 
		b = t; 
	}
};

struct CLUB {
	int cid, loc; 
	heap<PLAYER> priority_player; 
}club[11];

int main() {
	int player_id, power; 
	for (int i = 0; i < 3; i++) {
		player_id = i;  cin >> power; 
		club[0].priority_player.push({i, power});
	}
	cout << club[0].priority_player.size();
	return 0; 
}