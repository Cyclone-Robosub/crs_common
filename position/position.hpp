#pragma once

#include <array>
#include <ostream>
#include <iostream>
#include <memory>

class Position {
public:
    Position();
    Position(float x, float y, float z, float roll, float pitch, float yaw);
    Position(std::array<float, 6> values);

    float get_x();
    float get_y();
    float get_z();
    float get_roll();
    float get_pitch();
    float get_yaw();
    std::array<float,6> get_array_copy();

    float operator[](int value);
    friend bool operator==(const Position& lhs, const Position& rhs);
    friend bool operator==(const Position& lhs, const std::array<float, 6>& rhs);
    
    /// @brief Used primarily for waypoint/position comparisons. Should return true if
    /// we are within a certain tolerance of another position. Uses default tolerance of 0.2.
    /// @param rhs The other position (probably waypoint) that we want to compare to
    /// @returns True if we are within the tolerance, and false otherwise.
    bool AreWeThereYet(std::shared_ptr<Position> rhs);

    /// @brief Used primarily for waypoint/position comparisons. Should return true if
    /// we are within a certain tolerance of another position.
    /// @param rhs The other position (probably waypoint) that we want to compare to
    /// @param tolerance The tolerance that we want to use for the comparison
    /// @returns True if we are within the tolerance, and false otherwise.
    bool AreWeThereYet(std::shared_ptr<Position> rhs, float tolerance);
private:
    float x;
    float y;
    float z;
    float roll;
    float pitch;
    float yaw;
};