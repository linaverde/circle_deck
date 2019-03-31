#include <iostream>
#include <cstring>
#include "catch.hpp"
#include "deck_lib.h"

TEST_CASE("Deck is alive", "[deck]") {

    SECTION("Deck is succesfully created") {
        Deck a(5);
        Deck b(0);
    }

}

TEST_CASE("Pushing and popping elements from front", "[deck]") {

    SECTION("One element") {
        Deck a(10);
        a.length();
        CHECK(a.length() == 0);
        a.push_front(1);
        CHECK(a.length() == 1);
        CHECK(a.pop_front() == 1);
        CHECK(a.length() == 0);
    }

    SECTION("Some elements") {
        Deck a(10);
        CHECK(a.isEmpty());
        a.push_front(1);
        a.push_front(2);
        a.push_front(3);
        CHECK(!a.isEmpty());
        a.print();
        CHECK(a.length() == 3);
        CHECK(a.pop_front() == 3);
        CHECK(a.length() == 2);
        CHECK(a.pop_front() == 2);
        CHECK(a.length() == 1);
        CHECK(a.pop_front() == 1);
        a.print();
        CHECK(a.isEmpty());
    }

    SECTION("Circle") {
        Deck a(5);
        CHECK(a.isEmpty());
        a.push_front(1);
        a.push_front(2);
        a.push_front(3);
        a.push_front(4);
        a.print();
        CHECK(!a.isEmpty());
        CHECK(a.length() == 4);
        CHECK(a.pop_front() == 4);
        CHECK(a.pop_front() == 3);
        CHECK(a.length() == 2);
    }

}

TEST_CASE("Pushing and popping elements from back", "[deck]") {

    SECTION("One element") {
        Deck a (10);
        CHECK(a.length() == 0);
        a.push_back(1);
        CHECK(a.length() == 1);
        CHECK(a.pop_back() == 1);
        CHECK(a.length() == 0);
    }

    SECTION("Some elements") {
        Deck a (10);
        CHECK(a.isEmpty());
        a.push_back(1);
        a.push_back(2);
        a.push_back(3);
        a.print();
        CHECK(!a.isEmpty());
        CHECK(a.length() == 3);
        CHECK(a.pop_back() == 3);
        CHECK(a.length() == 2);
        CHECK(a.pop_back() == 2);
        CHECK(a.length() == 1);
        CHECK(a.pop_back() == 1);
        CHECK(a.isEmpty());
        a.print();
    }

    SECTION("Circle") {
        Deck a(5);
        a.push_back(1);
        a.push_back(2);
        a.push_back(3);
        a.push_back(4);
        a.print();
        CHECK(a.length() == 4);
        CHECK(a.pop_back() == 4);
        CHECK(a.pop_back() == 3);
        CHECK(a.length() == 2);
    }

}

TEST_CASE("Exceptions", "[deck]") {


    SECTION("Empty") {
        Deck a (10);
        REQUIRE_THROWS_WITH(a.pop_front(), "Deck is empty");
        REQUIRE_THROWS_WITH(a.pop_back(), "Deck is empty");
    }

    SECTION("Full"){
        Deck a(3);
        a.push_back(0);
        a.push_back(0);
        a.push_front(0);
        REQUIRE_THROWS_WITH(a.push_front(0), "Deck is full");
        REQUIRE_THROWS_WITH(a.push_back(0), "Deck is full");

        Deck b(3);
        b.push_front(0);
        b.push_front(0);
        b.push_back(0);
        REQUIRE_THROWS_WITH(a.push_front(0), "Deck is full");
        REQUIRE_THROWS_WITH(a.push_back(0), "Deck is full");
    }
}

TEST_CASE("Copy", "[deck]"){
    SECTION("Binary ="){
        Deck a(5);
        a.push_back(1);
        a.push_back(2);
        a.push_front(3);
        a.print();

        Deck b(3);
        b.push_back(0);

        b = a;

        b.print();

        CHECK(!b.isEmpty());
        CHECK(b.length() == a.length());
        CHECK(b.length() == 3);
        CHECK(b.getSize() == a.getSize());
        CHECK(b.getSize() == 5);
        CHECK(b.pop_front() == 3);
        CHECK(b.pop_back() == 2);
    }

    SECTION("Copy"){
        Deck a(5);
        a.push_back(1);
        a.push_back(2);
        a.push_front(3);
        a.print();

    }
}
