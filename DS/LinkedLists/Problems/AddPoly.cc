//Program to implement addition of two polynomials represented as linked list

#include <iostream>
using namespace std;
// Node structure containing power and coefficient of variable
class node
{
    public:
    int coeff;
    int pow;
    node *next;
};
             
// Function to create new node
void create_node(int x, int y, node **temp)
{
    node *r, *z;
    z = *temp;
    if(z == NULL)
    {
        r =new node;
        r->coeff = x;
        r->pow = y;
        *temp = r;
        r->next = new node;
        r = r->next;
        r->next = NULL;
    }
    else
    {
        r->coeff = x;
        r->pow = y;
        r->next = new node;
        r = r->next;
        r->next = NULL;
    }
}
 
// Function Adding two polynomial numbers
void polyadd(node *poly1, node *poly2, node *poly)
{
while(poly1->next && poly2->next)
    {
        // If power of 1st polynomial is greater then 2nd, then store 1st as it is
        // and move its pointer
        if(poly1->pow > poly2->pow)
        {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
         
        // If power of 2nd polynomial is greater then 1st, then store 2nd as it is
        // and move its pointer
        else if(poly1->pow < poly2->pow)
        {
            poly->pow = poly2->pow;
            poly->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
         
        // If power of both polynomial numbers is same then add their coefficients
        else
        {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff+poly2->coeff;
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
         
        // Dynamically create new node
        poly->next = new node;
        poly = poly->next;
        poly->next = NULL;
    }
while(poly1->next || poly2->next)
    {
        if(poly1->next)
        {
            poly->pow = poly1->pow;
            poly->coeff = poly1->coeff;
            poly1 = poly1->next;
        }
        if(poly2->next)
        {
            poly->pow = poly2->pow;
            poly->coeff = poly2->coeff;
            poly2 = poly2->next;
        }
        poly->next = new node;
        poly = poly->next;
        poly->next = NULL;
    }
}
 
// Display Linked list
void show(node *node)
{
while(node->next != NULL)
    {
    printf("%dx^%d", node->coeff, node->pow);
    node = node->next;
    if(node->next != NULL)
        printf(" + ");
    }
}
 
// Driver  program
int main()
{
    node *poly1 = NULL, *poly2 = NULL, *poly = NULL;
     
    // Create first list of 5x^2 + 4x^1 + 2x^0
    create_node(5,2,&poly1);
    create_node(4,1,&poly1);
    create_node(2,0,&poly1);
     
    // Create second list of 5x^1 + 5x^0
    create_node(5,1,&poly2);
    create_node(5,0,&poly2);
     
    printf("1st Number: "); 
    show(poly1);
     
    printf("\n2nd Number: ");
    show(poly2);
     
    poly = (struct node *)malloc(sizeof(struct node));
     
    // Function add two polynomial numbers
    polyadd(poly1, poly2, poly);
     
    // Display resultant List
    printf("\nAdded polynomial: ");
    show(poly);
 
return 0;
}