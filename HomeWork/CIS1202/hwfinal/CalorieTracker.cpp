#include "CalorieTracker.h"
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

// Base class definitions
CalorieTracker::CalorieTracker() : date(2025, 1, 1), foodCategory(Fruits), calories(0) {
}

CalorieTracker::CalorieTracker(Date d, FoodCategory fc, int c) {
    date = d;
    foodCategory = fc;
    calories = c;
}

void CalorieTracker::setDate(Date d) {
    date = d;
}

void CalorieTracker::setFoodCategory(FoodCategory fc) {
    foodCategory = fc;
}

void CalorieTracker::setCalories(int c) {
    calories = c;
}

Date CalorieTracker::getDate() {
    return date;
}

FoodCategory CalorieTracker::getFoodCategory() {
    return foodCategory;
}

int CalorieTracker::getCalories() const{
    return calories;
}

void CalorieTracker::displayEntry() const {
    string categories[] = { "Fruits", "Vegetables", "Grains", "Protein", "Dairy", "Sweets", "Beverages" };
    cout << setw(5) << date.month << "/" << setw(2) << date.day << "/" << date.year
        << setw(15) << categories[foodCategory]
        << setw(10) << calories << endl;
}

// Derived class definitions
DetailedCalorieTracker::DetailedCalorieTracker() : CalorieTracker(), mealType(breakfast) {
}

DetailedCalorieTracker::DetailedCalorieTracker(Date d, FoodCategory fc, int c, MealType mt)
    : CalorieTracker(d, fc, c), mealType(mt) {
}

void DetailedCalorieTracker::setMealType(MealType mt) {
    mealType = mt;
}

MealType DetailedCalorieTracker::getMealType() {
    return mealType;
}

void DetailedCalorieTracker::displayEntry() const {
    string categories[] = { "Fruits", "Vegetables", "Grains", "Protein", "Dairy", "Sweets", "Beverages" };
    string mealTypes[] = { "breakfast", "lunch", "dinner", "snack" };

    cout << setw(5) << date.month << "/" << setw(2) << date.day << "/" << date.year
        << setw(15) << categories[foodCategory]
        << setw(10) << calories
        << setw(12) << mealTypes[mealType] << endl;
}