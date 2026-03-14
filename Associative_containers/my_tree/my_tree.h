#ifndef MY_TREE_H
#define MY_TREE_H
#include <iostream>
#include <ostream>
#include <queue>
#include <vector>

template <typename T>
class my_tree {
private:
  class tree_node {
    public:
    explicit tree_node(const T& data);
    ~tree_node();
    T m_data;
    std::vector<tree_node*> m_children;
  };
  tree_node* m_parent;
private:
  tree_node* find_node(tree_node* node, const T& value) {
    if (!node) return nullptr;
    if (node->m_data == value) return node;

    for (tree_node* child : node->m_children) {
      tree_node* res = find_node(child, value);
      if (res) return res;
    }
    return nullptr;
  }
public:
  my_tree();
  void add_child(const T& parent_value, const T& child_value);
  void set_root(const T& parent_value);
  void bfs() const;
};

template<typename T>
my_tree<T>::tree_node::tree_node(const T& data)
  : m_data(data) {}

template<typename T>
my_tree<T>::tree_node::~tree_node() {
  m_children.clear();
}

template<typename T>
my_tree<T>::my_tree()
  : m_parent(nullptr) {}

template<typename T>
void my_tree<T>::add_child(const T &parent_value, const T &child_value) {
  tree_node* parent = find_node(m_parent, parent_value);
  if (!parent) {
    std::cout << "parent do not exist" << std::endl;
    return;
  }
  parent->m_children.push_back(new tree_node(child_value));
}

template<typename T>
void my_tree<T>::set_root(const T& parent_value) {
  if (m_parent != nullptr) {
    std::cout << "root already exists" << std::endl;
    return;
  }
  m_parent = new tree_node(parent_value);
}

template<typename T>
void my_tree<T>::bfs() const {
  if (!m_parent) return;

  std::queue<tree_node*> q;
  q.push(m_parent);

  while (!q.empty()) {
    tree_node* current = q.front();
    q.pop();

    std::cout << current->m_data << " ";

    for (tree_node* child : current->m_children) {
      q.push(child);
    }
  }
  std::cout << std::endl;
}


#endif //MY_TREE_H
