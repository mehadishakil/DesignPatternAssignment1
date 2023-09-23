# Design Patterns Demonstration

This repository contains the implementation and documentation of a project that demonstrates the understanding and application of various design patterns. The project aims to solve real-world scenarios by utilizing appropriate design patterns to achieve robust and maintainable solutions.

## Table of Contents

- [Introduction](#introduction)
- [Scenarios](#scenarios)
- [Implemented Design Patterns](#implemented-design-patterns)
- [Project Structure](#project-structure)
- [Usage](#usage)
- [Contributing](#contributing)
- [License](#license)

---

## Introduction

In the realm of software engineering, the application of design patterns plays a crucial role in achieving code maintainability, scalability, and overall system robustness. This project showcases the implementation of three design patterns across different scenarios, each addressing a unique problem.

## Scenarios

### Scenario 1

#### Case 1: CoolOS - Age-Specific Operating Systems

**Design Pattern**: Factory Method

**Specifications**: In this scenario, we address the challenge of creating age-specific operating systems efficiently. We have employed the Factory Method design pattern to produce age-specific operating systems tailored for different age groups, such as 7-12 and 13-16. The Factory Method pattern allows us to encapsulate the operating system creation process while providing flexibility for future expansion.

**OOP Design**: The class diagram and pseudo-code demonstrate the application of the Factory Method design pattern in generating age-specific operating systems.

**Discussion**: We justify the selection of the Factory Method pattern and contrast it with other patterns for similar purposes.

### Scenario 2

#### Case 4: NewsOnScreen - Subscription Service

**Design Pattern**: Observer

**Specifications**: In this case, we introduce a subscription service, NewsOnScreen, designed to notify subscribers of announcements from the Department of Computer Science at USW. The Observer design pattern is employed to establish a one-to-many relationship between subscribers and the service, allowing seamless updates and unsubscriptions.

**OOP Design**: The class diagram and pseudo-code illustrate the application of the Observer design pattern in implementing the NewsOnScreen subscription service.

**Discussion**: We provide a rationale for choosing the Observer pattern and compare it with alternative patterns serving a similar purpose.

### Scenario 3

#### Case 6: StudentCars - Inventory System

**Design Pattern**: Builder

**Specifications**: In this scenario, we address the inventory management system for StudentCars, a company offering two car models (Amaze and Awe) with various optional features. The Builder design pattern is utilized to construct complex car objects with different configurations, including radio systems, MP3 systems, leather seats, and wheel illumination.

**OOP Design**: The class diagram and pseudo-code exemplify the application of the Builder design pattern in creating configurable car models.

**Discussion**: We explain the rationale behind opting for the Builder pattern and contrast it with alternative patterns applicable to this inventory system.

---

## Implemented Design Patterns

This project demonstrates the following design patterns:

1. **Factory Method Pattern**: Implemented in Scenario 1, Case 1, for creating age-specific operating systems.

2. **Observer Pattern**: Implemented in Scenario 2, Case 4, for managing the NewsOnScreen subscription service.

3. **Builder Pattern**: Implemented in Scenario 3, Case 6, for designing and configuring car models in the StudentCars inventory system.

---

Feel free to clone this repository and experiment with the code.

## Contributing

If you have suggestions or improvements for any of the scenarios or design patterns, please feel free to contribute by opening an issue or a pull request.
