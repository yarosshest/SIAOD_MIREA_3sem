//
// Created by yaros on 23.05.2021.
//

#include "binary_tree.h"



binary_tree::binary_tree(){
    m_root = nullptr;
    size = 0;
}


tree_el* binary_tree::find(char key){
    tree_el* curr = m_root;
    while(curr != nullptr && curr->m_data != key){
        if(curr->m_data > key)
            curr = curr->m_left;
        else
            curr = curr->m_right;
    }
    return curr;
}

void val(tree_el* cur, vector<char> resp)
{
    if(cur != nullptr)
    {
        resp.push_back(cur->m_data);
        if(cur->m_right!=nullptr)
            val(cur->m_right, resp);

        if(cur->m_left!=nullptr)
            val(cur->m_left, resp);
    }
}


void binary_tree::print()
{
    node_print_state_t* _root_state = nullptr;
   m_root->print_subtree(_root_state);
}


void binary_tree::insert(char key)
{
    if (m_root == nullptr)
    {
        auto * root = new tree_el(key);
        m_root = root;
    }
    else
        m_root = m_root->Insert(key);
}



bool binary_tree::operator==(binary_tree treeE)
{
    bool result = false;
    result = m_root->equal(*treeE.m_root);
    return result;
}



string binary_tree::printLNR() {
    string result;
    m_root->printPath(result,'L','N','R');
    return result;
}


void binary_tree::wareGraph(string path) {
    vector<tree_el*> leaf;
    m_root->warePath(leaf,path[0],path[1],path[2]);
    for(int i=0; i<leaf.size(); ++i)
    {
        if((leaf[i]->m_left == NULL)&&(i!=0))
        {
            leaf[i]->m_left = (leaf[i-1]);
            leaf[i]->left_tag = true;
        }
        if((leaf[i]->m_right == NULL)&&(i!=leaf.size()-1))
        {
            leaf[i]->m_right = (leaf[i+1]);
            leaf[i]->right_tag = true;
        }
    }
}

binary_tree binary_tree::getSubtree(char key) {
    binary_tree tree;
    tree.m_root = find(key);
    return tree;
}


string binary_tree::GraphViz() {
    string result;
    result.append("https://quickchart.io/graphviz?graph=digraph{");
    m_root->GraphViz(result);
    result.append("}");
    return  result;
}


void binary_tree::Balance() {
    m_root = m_root->reBalance();
}

