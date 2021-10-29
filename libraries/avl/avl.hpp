#ifndef AVLTREE_HPP
#define AVLTREE_HPP

#include "../bst/bst.hpp"

namespace lasd{
  template typename<Data>
  class Avl : virtual public BST<Data>{
  protected:

    struct AvlNode : virtual public BinaryTreeLnk<Data>::NodeLnk{

    protected:
      ulong height;

    }
    
  }
}

#include "avl.cpp"

#endif
