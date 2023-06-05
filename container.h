// =========================================================
// File: container.h
// Author:
// Date:
// Description:
// =========================================================
#ifndef CONTAINER_H
#define CONTAINER_H

typedef enum{LIGHT, HEAVY, REFRIGERATED, LIQUID} ContainerType;

class Container {
protected:
  int id, weight;
  ContainerType type;

public:
  //Constructors
  Container(int, int, ContainerType);
  Container(const Container&);

  //Getters
  ContainerType getType() const;
  int getId() const;
  int getWeight() const;

  //Setters
  void setType(ContainerType);
  void setId(int);
  void setWeight(int);

  //Methods
  bool operator==(const Container*);
  bool operator==(const Container&);
  bool operator<(const Container*);
  bool operator<(const Container&);

  virtual double getConsumption() const = 0;
};

//Constructors
Container::Container(int _id, int _weight, ContainerType _type){
    id = _id;
    if (_weight < 0){
      weight = 0;
    } else {
      weight = _weight;
    }
    type = _type;
}

Container::Container (const Container &other){
    id = other.id;
    weight = other.weight;
    type = other.type;
}

//Getters
ContainerType Container::getType() const{
  return type;
}

int Container::getId() const{
  return id;
}

int Container::getWeight() const{
  return weight;
}

//Setters 
void Container::setId(int _id){
  id = _id;
}

void Container::setWeight(int _weight){
  weight = _weight;
}

void Container::setType(ContainerType _type){
  type = _type;
}

//Methods
bool Container::operator==(const Container* right){ 
  return id == right->id && weight == right->weight && type == right->type;
}

bool Container::operator==(const Container& right){ 
  return id == right.id && weight == right.weight && type == right.type;
}

bool Container::operator<(const Container* right){ 
  if (type == right -> type){
    return id < right->id;
  } else {
    return type < right->type;
  }
}

bool Container::operator<(const Container& right){ 
  if (type == right.type){
    return id < right.id;
  } else {
    return type < right.type;
  }
}

#endif