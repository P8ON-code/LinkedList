﻿#include <iostream>
#include <memory>
class List
{
private:
	struct Node
	{
		int value;
		std::shared_ptr<Node> next;
		Node(int tempValue, std::shared_ptr<Node> nextTmp): value(tempValue), next(nextTmp)
		{

		}

	};
	

	std::shared_ptr<Node> begin_ptr;
	std::shared_ptr<Node> end_ptr;
	size_t size;

	void init(int tempValue)
	{
		begin_ptr = std::make_shared<Node>(Node(tempValue, nullptr));
		end_ptr = begin_ptr;
		size = 1;
	}


public:
	List()
	{
		size = 0;
	}
	List(int tempValue)
	{
		size = 0;
		init(tempValue);
	}

	void push_back(int tempValue)
	{
		if (size == 0)
		{
			init(tempValue);
		}
		else
		{
			auto temp = std::make_shared<Node>(Node(tempValue, nullptr));
			(*end_ptr).next = temp;
			end_ptr = temp;
			++size;

		}

	}
	void push_front(int tempValue)
	{
		if (size == 0)
		{
			init(tempValue);
		}
		else
		{
			auto temp = std::make_shared<Node>(Node(tempValue, nullptr));
			(*temp).next = begin_ptr;
			begin_ptr = temp;
			++size;
		}
	}
	int at(int index)
	{
		if (index == 0)
		{
			return (*begin_ptr).value;
		}
		else
		{
			auto temp = begin_ptr;
			for (int i = 0; i < index; i++)
			{
				temp = (*temp).next;
			}
			return (*temp).value;
		}

	}
	int getFirst()
	{
		return (* begin_ptr).value;
	}
	int getLast()
	{
		return (*end_ptr).value;
	}
	size_t getSize()
	{
		return size;
	}
	void PrintAll()
	{
		auto temp = begin_ptr;
		for (int i = 0; i < (size); i++)
		{
			std::cout <<"Node nr."<<i<<" is equal to: " << (*temp).value << std::endl;
			temp = (*temp).next;
		}
	}
};


int main()
{
	List lista;
	for (int i=0; i < 20; i++)
	{
		lista.push_back(i+1);
		std::cout << lista.at(i) << std::endl;
	}


	std::cout << "\n\n\n";

	lista.PrintAll();

	//std::cout << lista.getSize() << std::endl;
	//std::cout<<"\n\n\n";
	






	return 0;
}