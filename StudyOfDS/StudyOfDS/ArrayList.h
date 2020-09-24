#pragma once
#include <iostream>
#include <string>
using namespace std;

#define MAXSIZE 1000

/** 
* @brief	array�� �̿��� sorted list
* @detail	� datatype�̵��� ����� �� �ֵ��� template�� �̿��ؼ� generic�ϰ� ����
* @date		2020-09-21
* @author	herrtane@gmail.com
* @version	����
*/

template <class T>
class ArrayList
{
private:
	int m_length;			// m_array���� ���Ҽ�
	int m_currentPos;		// m_array���� ���� ����Ű�� ��ġ
	T* m_array;				// m_array�� ����Ű�� ������

public:
	ArrayList();
	~ArrayList();

	/**
	* @brief	m_length�� ��ȯ���ִ� �Լ�
	* @date		2020-09-21
	* @return	m_length
	* @param	����
	*/
	int GetLength();
	/**
	* @brief	m_array�� ���� á���� ���θ� �˷��ִ� �Լ�
	* @date		���ݺ��ʹ� ����
	* @return	true or false
	* @param	����
	*/
	bool IsFull();
	/**
	* @brief	m_array�� ����ִ��� ���θ� �˷��ִ� �Լ�
	* @date		���ݺ��ʹ� ����
	* @return	true or false
	* @param	����
	*/
	bool IsEmpty();
	/**
	* @brief	m_array�� �� �迭�� ����
	* @date		����
	* @return	����
	* @param	����
	*/
	void MakeEmpty();

	/**
	* @brief	�迭�� ���� �ϳ��� id������ �°� �߰� 
	* @detail	�ش� itemtype�� operator overloading ���� �ʿ�, Binary Search�� ���� ����
	* @date		����
	* @return	������ 1, ���н� 0 ��ȯ
	* @param	���� �� T item
	*/
	int InsertItem(T item);
	/**
	* @brief	�迭���� ���� �ϳ��� ����
	* @detail	Binary Search�� ���� ����
	* @date		����
	* @return	������ 1, ���н� 0 ��ȯ
	* @param	������ T item
	*/
	int DeleteItem(T item);
	/**
	* @brief	���ڷ� ���� item�� id�� ��ġ�ϴ� �迭�� ���Ҹ� ã����
	* @detail	by Binary Search
	* @date		����
	* @return	������ 1, ���н� 0 ��ȯ
	* @param	ã����� T item
	*/
	int RetrieveItem(T& item);

	/**
	* @brief	m_currentPos�� -1�� �ʱ�ȭ
	* @date		����
	* @return	����
	* @param	����
	*/
	void ResetList();
	/**
	* @brief	m_currentPos�� ���� ���Ҹ� ��ȯ����
	* @date		����
	* @return	
	* @param	��ȯ���� ����� T item
	*/
	int GetNextItem(T& item);
};

template <class T>
ArrayList<T>::ArrayList() {
	m_length = 0;
	m_currentPos = -1;
	m_array = new T[MAXSIZE];
}

template <class T>
ArrayList<T>::~ArrayList() {
	delete[] m_array;
}

template <class T>
int ArrayList<T>::GetLength() {
	return m_length;
}

template <class T>
bool ArrayList<T>::IsFull() {
	if (m_length == MAXSIZE)
		return true;
	else
		return false;
}

template <class T>
bool ArrayList<T>::IsEmpty() {
	if (m_length <= 0)
		return true;
	else
		return false;
}

template <class T>
void ArrayList<T>::MakeEmpty() {
	m_length = 0;
}

template <class T>
int ArrayList<T>::InsertItem(T item) {
	if (!IsFull()) {

		int location = 0;

		while (location < m_length) {				// ���� insert�� ��ġ�� �ǳ��̶�� while���� ���Ƕ����� �������� �Ѿ ���̰�
													// ���� insert�� ��ġ�� �߰��̶�� item<m_array[location]�� �Ǹ� break�Ǿ� �������� �Ѿ ���̰�
													// ���� insert�� ��ġ�� �̹� �ٸ� ���Ұ� �ִٸ� 0�� ��ȯ�ϸ鼭 �ߴܵ� ���̴�.
			if (item < m_array[location])
				break;
			else if (item > m_array[location])
				location++;
			else
				return 0;
		}

		for (int i = m_length; i > location; i--)
			m_array[i] = m_array[i - 1];

		m_array[location] = item;
		m_length++;
		return 1;
	}

	return 0;
}

template <class T>
int ArrayList<T>::DeleteItem(T item) {
	int location;
	bool found = false;

	for (location = 0; location < m_length; location++) {
		if (item == m_array[location]) {
			found = true;
			break;
		}
	}

	if (!found)
		return 0;

	for (int i = location + 1; i < m_length; i++)
		m_array[i - 1] = m_array[i];
	m_length--;
	return 1;
}

template <class T>
int ArrayList<T>::RetrieveItem(T& item) {
	int midPoint;
	int first = 0;
	int last = m_length - 1;
	bool found = false;

	while ((first <= last) && !found) {

		midPoint = (first + last) / 2;

		if (item < m_array[midPoint])
			last = midPoint - 1;
		else if (item > m_array[midPoint])
			first = midPoint + 1;
		else {
			found = true;
			item = m_array[midPoint];
			return 1;
		}
	}
	return 0;
}

template <class T>
void ArrayList<T>::ResetList() {
	m_currentPos = -1;
}

template <class T>
int ArrayList<T>::GetNextItem(T& item) {
	m_currentPos++;
	if (m_currentPos == m_length)
		return 0;
	item = m_array[m_currentPos];
	return 1;
}