# Raytracer
## Introduce

This repository is a repository containing our second year project at Epitech The "Raytracer". The project consists in recreating raytracing is a 3D rendering algorithm, very different from the rendering algorithms used in the video game industry, in c++ thanks to the SFML graphical library.

# Table of content

* Introduce
* How Build
* Camera Controler
* Implement config file 
* Screenshots
* Features
* Dependancy
* Terminology
* Reference
* Disclaimer
* Author's Adresses

# How Build

```
mkdir build
cd build
cmake ..
cmake --build .
```

# Implement config file 

Create a .cfg file in the Config folder.
Create a list of elements in this list you can add all the objects you want to see in your scene.
A primitive object must contain a type, X, Y, Z positions. An AxisX, AxisY, AxisZ to choose the rotation of the primitive. Of course the size according to the primitive as the radius for the sphere characterize by r or width and lenght for the plane. Obviously the color in RGB.

Example:

```
elements:
{
    list = (
        {
            type = "Plane";
            x = 50;
            y = 0;
            z = 30;
            AxisX = 0;
            AxisY = 90;
            AxisZ = 0;
            width = 50;
            length = 50;
            color = { r = 255, g = 255, b = 0, };
        },
    );
};
```
            
# Camera Controler

```Z, Q, S, D``` for move in space and ```I, J, K, L``` for Axis vision rotate. Press ```Space``` to go up and ```shift``` to go down. 

# Screenshots

# Features

# Dependancy

You need SFML and liconfig++

# Terminology

## Lib SFML

SFML is a programming interface for building video games or interactive programs.

## C++

C++ is an object-oriented programming language.

## 3D

Three dimensions, three-dimensional or 3D are expressions that characterize the space that surrounds us.

# Reference

[libconfig](https://hyperrealm.github.io/libconfig/libconfig_manual.html)

# Disclaimer

If you are a student at Epitech, use the concepts used, not the code, or the cheat sheet will find you and give you a -42.

# Authors' Addresses

guillaume: guillaume.abel@epitech.eu,

tenshi: leonore.clos-manescau@epitech.eu,

badipvp: vincent.ballandi@epitech.eu,

swann: swann.lagoute@epitech.eu,

Epitech Toulouse