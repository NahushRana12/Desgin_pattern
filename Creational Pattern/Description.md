# Creational patterns

## What is a Creational Pattern?

Creational patterns are design patterns that deal with object creation mechanisms. They aim to create objects in a manner suitable to the situation. The main goal of creational patterns is to create objects in a way that is flexible and reusable, allowing for easier maintenance and scalability of the codebase.

A class creation pattern uses inheritance to create a new class, whereas an object creation pattern delegates the responsibility of instantiating a class to another class.

### Advantages of Creational Patterns:
1. **Encapsulation**: They encapsulate the knowledge of which concrete classes the system uses.
2. **Abstraction**: They hide how instances of the concrete classes are created, composed, and represented.

The client only needs to know the interface of the class it uses. It doesn't need to know how the class is implemented or how it is created. This allows for more flexibility and reusability in the codebase.

Sometimes, creational patterns are competitors of each other, providing different ways to achieve the same goal of object creation.

### Example: Building a Maze for a Computer Game

To study all five creational patterns, we will use a common example of building a maze for a computer game. The game and maze will vary from pattern to pattern. We'll ignore many details of what can be in a maze and whether a maze game has a single or multiple players. Instead, we'll just focus on how mazes get created. 

A maze is defined as a set of rooms. A room knows its neighbors; possible neighbors are another room, a wall, or a door to another room.

The class `MapSite` is the common abstract class for all the elements of a maze. To simplify the example, `MapSite` will have only one method, `Enter()`. This means you are overwriting your location if you can enter the room (if the door is open) or cannot enter (if the door is closed).

```cpp
class MapSite {
public:
    virtual void Enter() = 0;
};
```

The `Enter` method provides a simple basis for more sophisticated operations. For example, if you are in a room and say "go east," the game can determine which room is east of the current room and call `Enter()` on that room.

`Room` is the concrete subclass of `MapSite`. It maintains references to other `MapSite` objects and stores a room number. The number will be used to identify the room.

```cpp
class Room : public MapSite {
public:
    Room(int roomNo);
    MapSite* GetSide(Direction) const;
    void SetSide(Direction, MapSite*);
    virtual void Enter();
private:
    MapSite* _sides[4];
    int _roomNumber;
};
```

The following classes represent the wall or door that occurs on each side of a room.

```cpp
class Wall : public MapSite {
public:
    Wall();
    virtual void Enter();
};

class Door : public MapSite {
public:
    Door(Room* = 0, Room* = 0);
    virtual void Enter();
    Room* OtherSideFrom(Room*);
private:
    Room* _room1;
    Room* _room2;
    bool _isOpen;
};
```

We will also define a maze class to represent the maze. The maze class will be responsible for creating the maze and its components. The maze class will also provide methods to add rooms, walls, and doors to the maze.

```cpp
class Maze {
public:
    Maze();
    void AddRoom(Room*);
    Room* RoomNo(int) const;
private:
    // ...
};
```

`RoomNo` will look up the room number and return the room object. Another class we define is `MazeGame`, which creates the maze. One straightforward way to create a maze is with a series of operations that add components to a maze and then interconnect them. For example, the following member function will create a maze consisting of two rooms with a door between them:

```cpp
Maze* MazeGame::CreateMaze() {
    Maze* aMaze = new Maze;
    Room* r1 = new Room(1);
    Room* r2 = new Room(2);
    Door* theDoor = new Door(r1, r2);

    aMaze->AddRoom(r1);
    aMaze->AddRoom(r2);

    r1->SetSide(North, new Wall);
    r1->SetSide(East, theDoor);
    r1->SetSide(South, new Wall);
    r1->SetSide(West, new Wall);

    r2->SetSide(North, new Wall);
    r2->SetSide(East, new Wall);
    r2->SetSide(South, new Wall);
    r2->SetSide(West, theDoor);

    return aMaze;
}
```

This function is pretty complicated, considering that all it does is createa maze with two rooms and a door. But real probme with this uniform approach is that it is not flexible. If you want to create a different maze, you have to change the code. or you have different type of door or wall, you have to change the code. This is not a good design.

The Creational patterns are designed to solve this problem. They provide a way to create objects in a flexible and reusable manner. The five creational patterns are: Singleton, Factory Method, Abstract Factory, Builder, and Prototype.