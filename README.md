# PushSwap

Mathematics Behind PushSwap Algorithms

PushSwap is an intresting example of a sorting algorithm, it is not efficient at all, however it is perfect example of problem solving skills you can apply for creationg of sorting algorithms.

So let's look into a mathematics based approach of estimation for the total number of opperations of the Push_Swap alpgorithm.

# Basics of Push_Swap Algorithm

V.1 The rules

• You have 2 stacks named a and b.

• At the beginning:

◦ The stack a contains a random amount of negative and/or positive numbers
which cannot be duplicated.

◦ The stack b is empty.


• The goal is to sort in ascending order numbers into stack a. To do so you have the

following operations at your disposal:

sa (swap a): Swap the first 2 elements at the top of stack a.
Do nothing if there is only one or no elements.

sb (swap b): Swap the first 2 elements at the top of stack b.

Do nothing if there is only one or no elements.

ss : sa and sb at the same time.

pa (push a): Take the first element at the top of b and put it at the top of a.
Do nothing if b is empty.

pb (push b): Take the first element at the top of a and put it at the top of b.
Do nothing if a is empty.

ra (rotate a): Shift up all elements of stack a by 1.
The first element becomes the last one.

rb (rotate b): Shift up all elements of stack b by 1.
The first element becomes the last one.

rr : ra and rb at the same time.

rra (reverse rotate a): Shift down all elements of stack a by 1.
The last element becomes the first one.

rrb (reverse rotate b): Shift down all elements of stack b by 1.
The last element becomes the first one.

rrr : rra and rrb at the same time.

# Estimation of the opeations.

## Lets start with the simple algorithm

To estimate the opperations, we need to understand the main thing, Pushing to stack B takes X ammount of opperations, bushing to stack A takes Y ammount of opperations.

Now we can make a graph:

<img width="309" alt="Screen Shot 2023-05-02 at 5 45 16 PM" src="https://user-images.githubusercontent.com/49612380/235718809-7ea5c4e5-ef84-4793-b8d5-e57573547e45.png">
So The Graph in Uppwards direction would describe the opperations that it takes to push stack with 20 elements in direction A
So The Graph in Downwards direction would describe the opperations that it takes to push stack with 20 elements in direction B

As we can see the most optimal place to get the least ammount of opperations, is the middle ground, so most algorithms should target for finding this middle ground.


### Pushing to stack B

Lets now calculate opperations it takes to Push A Stack with 500 elements to Stack B

It takes 500 opperations, if we do not manipulate it in any way or form, but it is not useful for us.
So we can manipulate the stack to get some advantage in the sorting process. 

One of the simplest manipulates is sorting it into small segments:

So what we do is we push every element that is bigger then median to the stack b

We gain 2 stack with 250 elements, one of them is in stack A, one of them is in stack B, if we push it again we gain 500 elements in stack B, in 750 operations.

Now can we optimise this process.

#### YES 

So we push all elements to stack b, but depending from the median, we add an additional opperation rb, to make to stacks, without a struggle.

#### But you might wonder, it is the same ammount of opperations 750, how it is more efficient.

The thing is 2 stack, is still quiet big segment width, for sorting back algorithm and it will make the push B very inefficient, so we need to make more and smaller stacks.

Now if we use the first method to make 4 stack we would use:

#### 750 + 375 = 1125 (opperations) first method

Now if we use the secound method in combination with the first method, we gain 

#### 500 + 125 + 250 + 66 = 941 (opperations) 2nd method + 1 method 

while (len(stacka) == n/2)
if (n / 2 > element >  n / 4 )
  pb()
  rb()
else if (n / 4 > element > n)
  pb()
else ()
  ra()
}
update border and repeat

#### X = Ammount of Stacks
#### Y = Opperations
#### n = Ammount of elements

#### AS we can see we gained 941/1125 = 83% so we reduced the ammount of opperations for pushing multiple smaller stack by 17 %

if there is 6 stacks

#### First method
#### 500 + 417 + 333 + 250 + 83 + 166 = 83 * (1 + 6)/2 * 6 = 1743 (opperations) to push to stackB 6 smaller devision, with method 1
we can see that we can describe the formula with a Arithmetical Progression Times multiplayer

#### Second Method
#### 500 + 83 + 333 + 83 + 166 + 83 = 3 * 83 + 3 * (166 + 500)/2 * 3 = 1497 (opperations) 

First method:
So we can express the formula with expression
#### n/x * (1+x)/2 * x = y to push to stackB
Second method 
#### n/2 + (n/x + n)/2 * x/2 = y to push to stackB

Comparison if efficieny between 2 approaches
<img width="2560" alt="Screen Shot 2023-05-02 at 6 37 43 PM" src="https://user-images.githubusercontent.com/49612380/235729487-917503de-3930-4c03-bfe2-aa5db37e92da.png">

 Now lets add an algorithm for pushing back from Stack B

### Pushing to Stack A

For now lets just push from stack B to Stack A the top element.

So, for this we need to understand how many stack do we have, but that we descibe with the given X

#### So in case of n = 500 and x = 500, it would be 500 opperations
#### In case of n = 500 and x = 250 we can not predict the precise ammount of (opperations), it could be 500 or it could be rb pa rrb pb or (2000 opperations) lets take an average of 1000 (opperations)
#### For n = 500 and x = 125 it would be from 500 (opperations) to (rb rb pa rrb rrb pa rb pa rrb  pa) 1250 opperations worst case scenario
so we can make a formula that estimates lowest and maxiumum and medium ammount of opperations
#### For X ammount of stack we could say the Worst case scenario is 2 * (1 + x)* n = y 
Worst Case scenario 
<img width="2560" alt="Screen Shot 2023-05-02 at 7 34 13 PM" src="https://user-images.githubusercontent.com/49612380/235741566-abee1daa-f6e1-4c78-8ece-8ee83f8bae5a.png">

#### We can also estimate the avarage scenario (n + 2 * (1 + x) * n)/2 = y
Worst + Avarage Case Comparison
<img width="2560" alt="Screen Shot 2023-05-02 at 7 34 15 PM" src="https://user-images.githubusercontent.com/49612380/235741630-28e160e8-1dd7-4425-b360-70e0617552c3.png">



