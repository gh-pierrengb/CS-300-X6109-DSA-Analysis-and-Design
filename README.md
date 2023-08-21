# CS-300-X6109-DSA-Analysis-and-Design

### What was the problem you were solving in the projects for this course?
In the project, we were addressing the challenge of storing and efficiently retrieving course information, including the prerequisites for each course. The aim was to create a system that could handle large volumes of course data and enable swift searches.
### How did you approach the problem? Consider why data structures are important to understand.
The approach involved using a binary search tree (BST) as the primary data structure. Understanding data structures was crucial because the efficiency of operations (like insertions, deletions, and lookups) heavily depends on the choice of the data structure. The BST allowed us to take advantage of the properties of ordered data and perform operations in logarithmic time, making it an efficient choice for our needs.
### How did you overcome any roadblocks you encountered while going through the activities or project?
One of the challenges was handling the prerequisites, as courses can have multiple prerequisites. To address this, I modified the Course class to have a vector of pointers to prerequisite Course objects. Additionally, understanding the tree traversal to find a specific course was initially challenging. But with thorough testing and debugging, and by leveraging recursion, I was able to traverse the tree and fetch course details efficiently.
### How has your work on this project expanded your approach to designing software and developing programs?
This project has highlighted the importance of thoughtful design before diving into coding. It emphasized the significance of choosing the right data structure based on the problem's needs. I've learned that investing time in design can lead to more maintainable, efficient, and scalable software.
### How has your work on this project evolved the way you write programs that are maintainable, readable, and adaptable?
The project underscored the importance of writing clean and modular code. By separating functions and methods based on their responsibilities, I could quickly pinpoint issues and make modifications without affecting other parts of the codebase. Additionally, I've become more attentive to commenting and documenting my code to ensure that others (or myself in the future) can understand and modify it with ease.
