# Async-Web-Communicator

Multi-threaded application which allows to communicate between hosts. It's based on the client/server architecture.

<p align="center"> 
<img src="https://thumbs.gfycat.com/HardtofindSpicyImperatorangel-size_restricted.gif">
</p>


## Usage

~~~
$ awc.exe server yourname #server side
$ awc.exe client IP yourname #client side
~~~
Note: If the program is not added to your `$PATH` you should precede the name of the program with `./`

### Detailed information

Application utilizes IPv4 and TCP/IP protocol to communicate between hosts. Port is 4777. In order to make a connection firstly server side should listen on the port. When it's ready, others hosts can join to the session using clients.

### Contribute
If you found any bugs or want to add some fancy features to the application please make an issue. 
