<p align="center">
    <img src="https://www.42porto.com/wp-content/uploads/2024/08/42-Porto-Horizontal.png" alt="Pipex Image" />
</p>
<h1 align="center">Get next line</h1>
<p align="center">
    <img src="https://github.com/user-attachments/assets/4258ef7c-5659-418d-8e18-da68e25226d2" alt="Image" />
</p>

## Summary
<p>
    <b>Get next line </b> is a 42 school project with the goal of reading the next file from a given file descriptor. It should compile with the flag <b>-D</b>, which will define the buffer size for reading. For this, we need to learn what a static variable is and understand what file descriptors are and how to properly manage them.
</p>

## Code Phases
<details>
	<summary><b>Parsing</b></summary>
<ol>
    <li>First, we check if the file descriptor <b>(fd)</b> is smaller than 0. This happens because the first possible fd is <b>0</b>, which is standard input. <b>1</b> means <b>standard output</b> and <b>2</b> means <b>standard error</b>. After that, all other fds are created by the user, as shown in the example I provided in the main function using <b>open( )</b> to open some test files.</b></li>
	<li>Check if the macro <b>BUFFER_SIZE</b> is greater than 0, because its value will determine the number of characters we will read.</li>
</ol>
</details>

<details>
	<summary><b>Get the line and save it to the statig variable</b></summary>
<ol>
    <li>Call <b>copy_fd( )</b> to read from the provided file descriptor.</b>
	<ol>
		<li>Alocate memory fot hte <b>buffer</b> variable to storage the character read</b></li>
		<li><b>Call read( )</b> with the parameters <b>fd</b> (the file descriptor from which it will be reading), <b>buffer</b> (which is the array of characters that we allocate memory for) and <b>BUFFER_SIZE</b> (the number of characters to be read).</li>
		<li>It will be on a loop that continues until reaches the end of the file or finds the <b>'\n'</b> (meaning a new line).</li>
		<li>Call <b>add_to_strgs( )</b> on each iteration of the loop to add the content read to the static variable.</li>
		<li>Call <b>check_for_new_line( )</b> to check if the static variable already contains the new line.</li>
	</ol>
	<li>Check if the document is empty or if all the characters have already been read, and if so, return NULL.</li>
	<li>Call <b>verify_newline( )</b> to get the string for the program to return. There are a few possible outcomes for this function:
	<ol>
		<li>There is a new line and nothing else after it. Therefore, the program will save everything in the variable <b>next_line</b> and the static variable will be empty.</li>
		<li>There is a new line and more content after it. The <b>next_line</b> variable gets all the content up to the new line and the rest is kept in the static variable.</li>
		<li>There is no new line, so it will save all the content stored in the static variable to <b>next_line</b>.</li>
		<li>The first character is already a new line, so it saves only the new line in the <b>next_line</b> variable and keeps the rest in the static variable.</li>
	<ol>
</ol>
</details>

<details>
	<summary><b>Bonus</b></summary>
The bonus part of this program follows the exact same structure as the mandatory one, with the only difference being the static variable. In this case, it will be an array of char arrays that stores the values for each file descriptor (fd) sent to the program.
</details>

## Code Setup
<p>
    <b>Step 1:</b> Clone the repository
</p>

    git clone https://github.com/Hugofslopes/get_next_line

<p>
    <b>Step 2:</b> Open the terminal on the repo folder and write
</p>

    make

<p>
    <b>Step 3:</b> Execute main
</p>

    ./main

<p>
    <b>Step 4:</b> Execute main bonus
</p>

    make bonus ; ./mainbonus
