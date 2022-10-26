#include "tree_el.h"

tree_el::tree_el(char key)
{
    m_data = key;
    height = 1;
    m_left = nullptr;
    m_right = nullptr;
    left_tag = false;
    right_tag = false;
}


tree_el::tree_el()
{
    m_data = NULL;
    height = NULL;
    m_left = nullptr;
    m_right = nullptr;
    left_tag = false;
    right_tag = false;
}



tree_el::tree_el(char key,tree_el* left,tree_el* right)
{
    m_data = key;
    m_left = left;
    m_right = right;
    height = max(left->height, right->height)+1;
}



void tree_el::fixheight()
{
    int heightL = 0;
    int heightR = 0;

    if ((m_left != nullptr)&&(!left_tag)) heightL = m_left->height;
    if ((m_right != nullptr)&&(!right_tag)) heightR = m_right->height;

    height = max(heightL, heightR)+1;
}

int tree_el::bf()
{
    int heightL = 0;
    int heightR = 0;

    if ((m_left != NULL)&&(!left_tag)) heightL = m_left->height;
    if ((m_right != NULL)&&(!right_tag)) heightR = m_right->height;

    return heightR-heightL;
}


tree_el* tree_el::RightRotation()
{
    tree_el *y=m_left;
    m_left=y->m_right;
    y->m_right=this;
    this->fixheight();
    y->fixheight();
    return y;
}


tree_el* tree_el::LeftRotation()
{
    tree_el *x= m_right;
    m_right=x->m_left;
    x->m_left=this;
    x->fixheight();
    this->fixheight();
    return x;
}



tree_el* tree_el::Balance()
{
    this->fixheight();
    if (this->bf()==2)
    {
        if (m_right->bf()<0) m_right=m_right->RightRotation();
        return this->LeftRotation();
    }
    if (this->bf()==-2)
    {
        if (m_left->bf()>0) m_left=m_left->LeftRotation();
        return this->RightRotation();
    }
    return this;
}


tree_el* tree_el::Insert(char k)
{
    if (!this) return new tree_el(k);
    if (k<m_data)
        m_left= m_left->Insert(k);
    else
        m_right=m_right->Insert(k);
    return this->Balance();
}


void tree_el::print_subtree(node_print_state_t* _root_state) {
    node_print_state_t* parent_state;
    if (_root_state != nullptr) {
        printf(" ");
        node_print_state_t* s = _root_state;
        while (s->child_state != nullptr) {
            printf(s->printing_last_child ? "  " : "| ");
            s = s->child_state;
        }
        parent_state = s;
        printf(parent_state->printing_last_child ? "L" : "+");
    } else {
        parent_state = nullptr;
    }
    printf(">%i\n", m_data);

    if (((m_left != nullptr)&&(!left_tag)) || ((m_right != nullptr)&&(!right_tag))) {
        node_print_state_t s{};
        if (parent_state != nullptr) {
            parent_state->child_state = &s;
        } else {
            _root_state = &s;
        }
        s.child_state = nullptr;

        if ((m_left != nullptr)&&(!left_tag)) {
            s.printing_last_child = (m_right == nullptr);
            m_left->print_subtree(_root_state);
        }
        if ((m_right != nullptr)&&(!right_tag)) {
            s.printing_last_child = true;
            m_right->print_subtree(_root_state);
        }

        if (parent_state != nullptr) {
            parent_state->child_state = nullptr;
        } else {
            _root_state = nullptr;
        }
    }
}


bool tree_el::equal(tree_el el) {
    if(m_data == el.m_data)
    {
        bool eqL = false;
        bool eqR = false;

        if((((m_right != nullptr)&&(!right_tag)))&&(el.m_right != nullptr))
            bool eqR = m_right->equal(*el.m_right);

        if(((m_left != nullptr)&&(!left_tag))&&(el.m_left != nullptr))
            bool eqL = m_left->equal(*el.m_left);

        if (eqL && eqR) return true;
        else return false;
    }
    else return false;
}


char tree_el::min() {
    if ((m_left != nullptr)&&(!left_tag)) return m_left->min();
    else return m_data;
}


void tree_el::printPath(string &result, char first, char second, char third) {
    wayPrintPath(result,first,first,second,third);
    wayPrintPath(result,second,first,second,third);
    wayPrintPath(result,third,first,second,third);
}


string toString(const char &value) {
    std::ostringstream os;
    os << value;
    return os.str();
}


void tree_el::wayPrintPath(string &result, char command,char first,char second ,char third) {
    string res;

    switch (command)
    {
        case 'N':
            if(result.empty())
                res =toString(m_data);
            else
                res = ',' + toString(m_data);
            result.append(res);
            break;
        case 'R':
            if((m_right != nullptr)&&(!right_tag))
                m_right->printPath(result,first,second,third);
            break;

        case 'L':
            if((m_left != nullptr)&&(!left_tag))
                m_left->printPath(result,first,second,third);
            break;


    }
}


void tree_el::warePath(vector<tree_el*>& leaf,char first,char second ,char third) {
    wayWarePath(leaf,first,first,second,third);
    wayWarePath(leaf,second,first,second,third);
    wayWarePath(leaf,third,first,second,third);
}


void tree_el::wayWarePath(vector<tree_el*>& leaf, char command, char first, char second, char third) {
    switch (command)
    {
        case 'N':
            leaf.push_back(this);
            break;
        case 'R':
            if((m_right != nullptr)&&(!right_tag))
                m_right->warePath(leaf,first,second,third);
            break;

        case 'L':
            if((m_left != nullptr)&&(!left_tag))
                m_left->warePath(leaf,first,second,third);
            break;
    }
}

void tree_el::GraphViz(string &result) {
    if((m_left != nullptr)&&(!left_tag))
    {
        string data1 = toString(m_data);
        string data2 = toString(m_left->m_data);
        result.append(data1+"->"+data2+";");
    }
    if((m_right != nullptr)&&(!right_tag))
    {
        string data1 = toString(m_data);
        string data2 = toString(m_right->m_data);
        result.append(data1+"->"+data2+";");
    }
    if((m_left != nullptr)&&(left_tag))
    {
        string data1 = toString(m_data);
        string data2 = toString(m_left->m_data);
        result.append(data1+"->"+data2 +" [style=dotted];");
    }
    if((m_right != nullptr)&&(right_tag))
    {
        string data1 = toString(m_data);
        string data2 = toString(m_right->m_data);
        result.append(data1+"->"+data2 + " [style=dotted];");
    }
    if((m_right != nullptr)&&(!right_tag))
        m_right->GraphViz(result);
    if((m_left != nullptr)&&(!left_tag))
        m_left->GraphViz(result);
}


tree_el *tree_el::reBalance() {
    if((m_left != nullptr)&&(!left_tag))
        m_left = m_left->Balance();
    if((m_right != nullptr)&&(!right_tag))
        m_right = m_right->Balance();
    if((m_left != nullptr)&&(!left_tag))
        m_left = m_left->Balance();
    if((m_right != nullptr)&&(!right_tag))
        m_right->reBalance();
    if((m_left != nullptr)&&(!left_tag))
        m_left->reBalance();
    return Balance();
}


tree_el *tree_el::SearchMin(tree_el *x)
{
    if (x->m_left) return SearchMin(x->m_left);
    else return x;
}



tree_el *tree_el::DeleteMin(tree_el *x)
{
    if (x->m_left==0) return x->m_left;
    x->m_left=DeleteMin(x->m_left);
    return x->Balance();
}


tree_el* tree_el::delete_elem(char key) {
    if ((key<m_data)&&(m_left != nullptr)&&(!left_tag)) m_left = m_left->delete_elem(key);
    else if ((key>m_data)&&(m_right != nullptr)&&(!right_tag)) m_right=m_right->delete_elem(key);
    else
    {
        tree_el *y=m_left;
        tree_el *z=m_right;
        delete this;
        if (!z) return y;
        tree_el* min=SearchMin(z);
        min->m_right=DeleteMin(z);
        min->m_left=y;
        return min->Balance();
    }
    return this->Balance();
}

ostream &operator<<(ostream &out, tree_el &point) {
    return  out << point.m_data << " ";
}
