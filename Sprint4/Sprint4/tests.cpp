#include "catch.h"
#include "LinkedList.h"
#include "DSStack.h"
#include "AdjList.h"

#include <iostream>
using namespace std;
TEST_CASE("get size of linked list", ".getSize()"){
    LinkedList<int> x;

    x.insertEnd(1);
    x.insertEnd(2);

    REQUIRE(x.getSize() == 2);

    x.insertEnd(1);
    x.insertEnd(2);

    REQUIRE(x.getSize() == 4);

    x.insertEnd(1);
    x.insertEnd(2);

    REQUIRE(x.getSize() == 6);

    x.insertEnd(1);
    x.insertEnd(2);

    REQUIRE(x.getSize() == 8);

    x.insertEnd(1);

    REQUIRE(x.getSize() == 9);
}

TEST_CASE("insert node at front",".insertFront(S x)"){
    LinkedList<int> x;

    x.insertFront(9);
    REQUIRE(x.returnFront() == 9);

    x.insertFront(8);
    REQUIRE(x.returnFront() == 8);

    x.insertFront(5);
    REQUIRE(x.returnFront() == 5);

    x.insertFront(2);
    REQUIRE(x.returnFront() == 2);

    x.insertFront(9);
    REQUIRE(x.returnFront() == 9);
}

TEST_CASE("insert node at end",".insertEnd(S x)"){
    LinkedList<int> x;

    x.insertEnd(5);
    REQUIRE(x.returnBack() == 5);

    x.insertEnd(10);
    REQUIRE(x.returnBack() == 10);

    x.insertEnd(4);
    REQUIRE(x.returnBack() == 4);

    x.insertEnd(2);
    REQUIRE(x.returnBack() == 2);

    x.insertEnd(9);
    REQUIRE(x.returnBack() == 9);
}

TEST_CASE("delete front node",".deleteFront()"){
    LinkedList<int> x;

    x.insertEnd(2);
    x.insertEnd(5);
    x.insertEnd(11);
    x.insertEnd(20);
    x.insertEnd(23);
    x.insertEnd(2);

    x.deleteFront();
    REQUIRE(x.returnFront() == 5);

    x.deleteFront();
    REQUIRE(x.returnFront() == 11);

    x.deleteFront();
    REQUIRE(x.returnFront() == 20);

    x.deleteFront();
    REQUIRE(x.returnFront() == 23);

    x.deleteFront();
    REQUIRE(x.returnFront() == 2);
}

TEST_CASE("delete back node",".deleteBack()"){
    LinkedList<int> x;

    x.insertEnd(2);
    x.insertEnd(5);
    x.insertEnd(11);
    x.insertEnd(20);
    x.insertEnd(23);
    x.insertEnd(2);

    x.deleteBack();
    REQUIRE(x.returnBack() == 23);

    x.deleteBack();
    REQUIRE(x.returnBack() == 20);

    x.deleteBack();
    REQUIRE(x.returnBack() == 11);

    x.deleteBack();
    REQUIRE(x.returnBack() == 5);

    x.deleteBack();
    REQUIRE(x.returnBack() == 2);
}

TEST_CASE("see if stack contains an element, returns index", ".contains(S x)"){
    LinkedList<int> LL;

    LL.insertEnd(2);
    LL.insertEnd(5);
    LL.insertEnd(11);
    LL.insertEnd(20);
    LL.insertEnd(23);
    LL.insertEnd(2);

    REQUIRE(LL.contains(2) == 0);
    REQUIRE(LL.contains(11) == 2);
    REQUIRE(LL.contains(21) == -1);
    REQUIRE(LL.contains(50) == -1);
    REQUIRE(LL.contains(5) == 1);
}

TEST_CASE("if stack is empty", ".empty()"){
    DSStack<int> s;

    s.push(5);
    s.push(6);

    REQUIRE(s.empty() == false);

    s.pop();

    REQUIRE(s.empty() == false);

    s.pop();

    REQUIRE(s.empty() == true);

    s.push(9);
    s.pop();

    REQUIRE(s.empty() == true);

    s.push(10);

    REQUIRE(s.empty() == false);
}

TEST_CASE("return value on top of the stack", ".top()"){
    DSStack<int> s;

    s.push(5);
    s.push(6);

    REQUIRE(s.top() == 6);

    s.pop();

    REQUIRE(s.top() == 5);

    s.pop();
    s.push(3);

    REQUIRE(s.top() == 3);

    s.push(9);
    s.pop();

    REQUIRE(s.top() == 3);

    s.push(10);

    REQUIRE(s.top() == 10);
}

TEST_CASE("push something onto stack", ".push(const T& x)"){
    DSStack<int> s;

    s.push(5);
    s.push(6);

    REQUIRE(s.top() == 6);

    s.pop();

    REQUIRE(s.top() == 5);

    s.pop();
    s.push(3);

    REQUIRE(s.top() == 3);

    s.push(9);
    s.pop();

    REQUIRE(s.top() == 3);

    s.push(10);

    REQUIRE(s.top() == 10);
}

TEST_CASE("remove and return value on top of the stack", ".pop()"){
    DSStack<int> s;

    s.push(5);
    s.push(6);
    s.push(7);
    s.push(8);
    s.push(5);

    REQUIRE(s.pop() == 5);
    REQUIRE(s.pop() == 8);
    REQUIRE(s.pop() == 7);
    REQUIRE(s.pop() == 6);
    REQUIRE(s.pop() == 5);
}

TEST_CASE("pushback ALData onto origins list of adjacency list", ".pushback(ALData&)"){
    AdjList a;

    a.pushback(ALData("Atlanta"));
    REQUIRE(a.getLength() == 1);

    a.pushback(ALData("El Paso"));
    REQUIRE(a.getLength() == 2);

    a.pushback(ALData("Nice"));
    REQUIRE(a.getLength() == 3);

    a.pushback(ALData("Dallas"));
    REQUIRE(a.getLength() == 4);

    a.pushback(ALData("New York City"));
    REQUIRE(a.getLength() == 5);
}

TEST_CASE("returns the length of the adjacency list", ".getLength()"){
    AdjList a;

    a.pushback(ALData("Atlanta"));
    REQUIRE(a.getLength() == 1);

    a.pushback(ALData("El Paso"));
    REQUIRE(a.getLength() == 2);

    a.pushback(ALData("Nice"));
    REQUIRE(a.getLength() == 3);

    a.pushback(ALData("Dallas"));
    REQUIRE(a.getLength() == 4);

    a.pushback(ALData("New York City"));
    REQUIRE(a.getLength() == 5);
}
