#ifndef ITERATOR_H
#define ITERATOR_H

#include "struct.h"
#include "list.h"
#include <iostream>
#include <stack>
#include <queue>
using namespace std;

template <class T>
class Iterator
{
public:
  virtual void first() = 0;
  virtual void next() = 0;
  virtual T currentItem() const = 0;
  virtual bool isDone() const = 0;
};

template <class T>
class NullIterator : public Iterator<T>
{
public:
  NullIterator(Term *n) {}
  void first() {}
  void next() {}
  Term *currentItem() const
  {
    return nullptr;
  }
  bool isDone() const
  {
    return true;
  }
};

template <class T>
class StructIterator : public Iterator<T>
{
public:
  friend class Struct;
  void first()
  {
    _index = 0;
  }

  Term *currentItem() const
  {
    return _s->args(_index);
  }

  bool isDone() const
  {
    return _index >= _s->arity();
  }

  void next()
  {
    _index++;
  }

private:
  StructIterator(Struct *s) : _index(0), _s(s) {}
  int _index;
  Struct *_s;
};

template <class T>
class ListIterator : public Iterator<T>
{
public:
  ListIterator(List *list) : _index(0), _list(list) {}

  void first()
  {
    _index = 0;
  }

  Term *currentItem() const
  {
    return _list->args(_index);
  }

  bool isDone() const
  {
    return _index >= _list->arity();
  }

  void next()
  {
    _index++;
  }

private:
  int _index;
  List *_list;
};

template <class T>
class BFSIterator : public Iterator<T>
{
public:
  BFSIterator(T BFS) : _index(0), _BFS(BFS) {}

  void first()
  {
    _BFSqueue.push(_BFS);
    while (!_BFSqueue.empty())
    {
      temp = _BFSqueue.front();
      _BFSqueue.pop();

      if (_BFS != temp)
      {
        _BFSTerms[i] = temp;
        i++;
      }
      BFS(temp);
    }
  }

  void next()
  {
    _index++;
  }

  bool isDone() const
  {
    return _BFSqueue.empty();
  }

  Term *currentItem() const
  {
    return _BFSTerms[_index];
  }

  void BFS(T temp)
  {
    Iterator<T> *it = temp->createIterator();
    for (it->first(); !it->isDone(); it->next())
    {
      _BFSqueue.push(it->currentItem());
    }
  }

private:
  int _index, i = 0;
  T _BFS;
  T temp;
  queue<T> _BFSqueue;
  T _BFSTerms[20];
  int text;
};

template <class T>
class DFSIterator : public Iterator<T>
{
public:
  DFSIterator(Term *term) : _index(0), _DFS(term) {}
  void first()
  {
    Iterator<Term *> *it = _DFS->createIterator();
    for (it->first(); !it->isDone(); it->next())
    {
      dfs.push_back(it->currentItem());
    }
    for (int i = 0; i < dfs.size(); i++)
    {
      DFS(dfs[i]);
    }
  }

  Term *currentItem() const
  {
    return _DFSvector[_index];
  }
  bool isDone() const
  {
    return !_DFSvector.empty();
  }
  void next()
  {
    _index++;
  }

  void DFS(Term *temp)
  {
    Iterator<Term *> *it = temp->createIterator();
    _DFSvector.push_back(temp);
    for (it->first(); !it->isDone(); it->next())
    {
      DFS(it->currentItem());
    }
  }

private:
  int _index;
  Term *_DFS;
  vector<Term *> _DFSvector;
  vector<Term *> dfs;
};
#endif
