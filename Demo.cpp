/**
 * Demo app for Ex4
 */
#include <iostream>
#include <string>
#include "node.hpp"
#include "tree.hpp"

using namespace std;

int main()
{

    Node root_node = Node("root");
    Tree tree;
    tree.add_root(root_node);
    Node n1 = Node(1);
    Node n2 = Node("n2");
    Node n3 = Node(12.35);
    Node n4 = Node(1 / 4);
    Node n5 = Node("n5");
    Node n6 = Node("n6");
    Node n7 = Node("n7");

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(root_node, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n1, n5);
    tree.add_sub_node(n2, n6);
    tree.add_sub_node(n2, n7);
    // The tree should look like:
    /**
     * root
     * |__1
     * |  |__0.25
     * |  |__n5
     * |__n2
     * |  |__n6
     * |  |__n7
     * |__12.35
     */

    for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node)
    {
        cout << node->get_value() << endl;
    } // prints: root, 1, 0.25, n5, n2, n6, n7, 12.35

    for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
    {
        cout << node->get_value() << endl;
    } // prints: 0.25, n5, 1, n6, n7, n2, 12.35, root

    for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
    {
        cout << node->get_value() << endl;
    } // prints: 0.25, 1, n5, root, n6, n2, n7, 12.35

    for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
    {
        cout << node->get_value() << endl;
    } // prints: root, 1, n2, 12.35, 0.25, n5, n6, n7

    for (auto node : tree)
    {
        cout << node.get_value() << endl;
    } // same as BFS: root, 1, n2, 12.35, 0.25, n5, n6, n7

    cout << tree; // Should print the graph using GUI.
}