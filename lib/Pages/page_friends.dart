import 'package:flutter/material.dart';
import 'package:application/style.dart' as style;
import 'package:application/connection.dart' as db;

class FriendsPage extends StatefulWidget {
  const FriendsPage({super.key});

  @override
  State<FriendsPage> createState() => _FriendsPageState();
}

class _FriendsPageState extends State<FriendsPage> {

  String username = db.user;
  List<String> friendList = [];
  List<String> requestsList = [];
  List<String> userList = [];

  // The text editing controller is used to capture user input and pass it into
  // local copies of data through dialog boxes
  late TextEditingController controller;

  @override
  void initState() {
    super.initState();

    initializeLists();

    controller = TextEditingController();
  }

  @override
  void dispose() {
    controller.dispose();

    super.dispose();
  }

  void initializeLists() async {
    List<List<dynamic>> results = await db.connection.query("SELECT UNNEST(friends) AS friends FROM friends WHERE username='$username'");

    print("initializing friends...");
    setState(() {
      friendList.clear();

      for (final row in results) {
        friendList.add(row[0]);
      }
    });

    results = await db.connection.query("SELECT from_user FROM requests WHERE to_user='$username'");

    print("initializing requests...");
    setState(() {
      requestsList.clear();

      for (final row in results) {
        requestsList.add(row[0]);
      }
    });

    results = await db.connection.query("SELECT username FROM users");

    print("initializing users...");
    setState(() {
      userList.clear();

      for (final row in results) {
        userList.add(row[0]);
      }
    });
  }

  void sendFriendRequest(String newFriend) async {
    List<List<dynamic>> results = await db.connection.query("SELECT * FROM requests WHERE from_user='$username' AND to_user='$newFriend'");

    if (results.isEmpty) {
      print("Request doesn't exist!");
      await db.connection.query("INSERT INTO requests (from_user, to_user) VALUES ('$username', '$newFriend')");
    }
  }

  void acceptFriendRequest(String newFriend) async {

    await db.connection.query("UPDATE friends SET friends=ARRAY_APPEND(friends,'$newFriend') WHERE username='$username'");
    await db.connection.query("UPDATE friends SET friends=ARRAY_APPEND(friends,'$username') WHERE username='$newFriend'");

    await db.connection.query("DELETE FROM requests WHERE to_user='$username' AND from_user='$newFriend'");

    setState(() {
      friendList.add(newFriend);
    });

  }

  void rejectFriendRequest(String friend) async {

    await db.connection.query("DELETE FROM requests WHERE to_user='$username' AND from_user='$friend'");

  }

  void removeFriend(String friend) async {
    await db.connection.query("UPDATE friends SET friends=ARRAY_REMOVE(friends,'$friend') WHERE username='$username'");
    await db.connection.query("UPDATE friends SET friends=ARRAY_REMOVE(friends,'$username') WHERE username='$friend'");
  }

  Future<String?> openTextEntryDialog() => showDialog<String>(
    context: context,
    builder: (context) => AlertDialog(
      title: Text("Enter username", style: style.textStyle),
      backgroundColor: style.backgroundAccent,
      content: TextField(
        decoration: InputDecoration(
          hintText: "Enter username here",
          hintStyle: style.subtextStyle,
        ),
        controller: controller,
        onSubmitted: (_) => submitText(),
        style: style.textStyle,
      ),
      actions: [
        TextButton(
          onPressed: submitText,
          style: TextButton.styleFrom(
            foregroundColor: style.mainColor,
          ),
          child: const Text("ADD FRIEND"),
        )
      ],
    ),
  );

  void submitText() {
    Navigator.of(context).pop(controller.text);

    controller.clear();
  }

  void errorNullDialog() => showDialog(
    context: context,
    builder: (context) => AlertDialog(
      backgroundColor: style.backgroundColor,
      title: Text("Error: Please enter a username", style: style.textStyle),
      actions: [
        TextButton(
          onPressed: close,
          style: TextButton.styleFrom(
            foregroundColor: style.mainColor,
          ),
          child: const Text("OK"),
        )
      ],
    ),
  );

  void errorFriendExistsDialog() => showDialog(
    context: context,
    builder: (context) => AlertDialog(
      backgroundColor: style.backgroundColor,
      title: Text("Error: Friend has already been added", style: style.textStyle),
      actions: [
        TextButton(
          onPressed: close,
          style: TextButton.styleFrom(
            foregroundColor: style.mainColor,
          ),
          child: const Text("OK"),
        )
      ],
    ),
  );

  void errorRequestExistsDialog() => showDialog(
    context: context,
    builder: (context) => AlertDialog(
      backgroundColor: style.backgroundColor,
      title: Text("Error: This friend has already requested to be added", style: style.textStyle),
      actions: [
        TextButton(
          onPressed: close,
          style: TextButton.styleFrom(
            foregroundColor: style.mainColor,
          ),
          child: const Text("OK"),
        )
      ],
    ),
  );

  void errorNonexistentUserDialog() => showDialog(
    context: context,
    builder: (context) => AlertDialog(
      backgroundColor: style.backgroundColor,
      title: Text("Error: User doesn't exist", style: style.textStyle),
      actions: [
        TextButton(
          onPressed: close,
          style: TextButton.styleFrom(
            foregroundColor: style.mainColor,
          ),
          child: const Text("OK"),
        )
      ],
    ),
  );

  void close() {
    Navigator.of(context).pop(context);
  }

  bool friendExists(String newFriend) {

    for (String friend in friendList) {
      if (friend == newFriend) {
        return true;
      }
    }

    return false;
  }

  bool requestExists(String newRequest) {

    for (String request in requestsList) {
      if (request == newRequest) {
        return true;
      }
    }

    return false;
  }

  bool userExists(String user) {

    for (String name in userList) {
      if (name == user) {
        return true;
      }
    }

    return false;
  }

  @override
  Widget build(BuildContext context) {

    return Scaffold(
      backgroundColor: style.backgroundColor,
      appBar: AppBar(
        // Here we take the value from the MyHomePage object that was created by
        // the App.build method, and use it to set our appbar title.
        title: const Text("Friends"),
        backgroundColor: style.mainColor,
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.spaceEvenly,
          children: [
            const Text("Requests:"),
            Expanded(
              child: ListView.builder(
                  itemCount: requestsList.length,
                  itemBuilder: (BuildContext context, int index) {
                    return Card(
                        child: ListTile(
                          title: Text(requestsList[index]),
                          trailing: SizedBox(
                            height: 80,
                            width: 80,
                            child: Row(
                              children: [
                                IconButton(
                                  icon: const Icon(Icons.check),
                                  onPressed: () {
                                    acceptFriendRequest(requestsList[index]);

                                    setState(() {
                                      requestsList.removeAt(index);
                                    });
                                  },
                                ),
                                IconButton(
                                  icon: const Icon(Icons.close),
                                  onPressed: () {
                                    rejectFriendRequest(requestsList[index]);

                                    setState(() {
                                      requestsList.removeAt(index);
                                    });
                                  },
                                ),
                              ],
                            ),
                          ),
                        )
                    );
                  }
              ),
            ),
            Padding(
              padding: const EdgeInsets.all(20.0),
              child: FloatingActionButton.extended(
                heroTag: "Add",
                onPressed: () async {
                  final newFriend = await openTextEntryDialog();
                  if (newFriend == null || newFriend.isEmpty) {
                    errorNullDialog();
                    return;
                  } else if (friendExists(newFriend)) {
                    errorFriendExistsDialog();
                    return;
                  } else if (requestExists(newFriend)) {
                    errorRequestExistsDialog();
                    return;
                  } else if (!userExists(newFriend)) {
                    errorNonexistentUserDialog();
                    return;
                  }

                  sendFriendRequest(newFriend);
                },
                label: Text("Add Friend", style: style.buttonTextStyle),
                backgroundColor: style.mainColor,
                foregroundColor: style.backgroundColor,
              ),
            ),
            const Text("Friends:"),
            Expanded(
              child: ListView.builder(
                  itemCount: friendList.length,
                  itemBuilder: (BuildContext context, int index) {
                    return Card(
                        child: ListTile(
                          title: Text(friendList[index]),
                          trailing: IconButton(
                            icon: const Icon(Icons.delete),
                            onPressed: () {

                              removeFriend(friendList[index]);

                              setState(() {
                                friendList.removeAt(index);
                              });
                            },
                          ),
                        )
                    );
                  }
              ),
            ),
          ],
        ),
      ),

      // The bottom navigation bar allows for easy access to the three main pages of the application
      bottomNavigationBar: BottomAppBar(
        // This padding makes the icons look cleaner and increase readability for the user
        padding: const EdgeInsets.all(5.0),

        // This color specification allows dark mode to function, as the theme settings in main
        // are only set when the application is initially started
        color: style.backgroundAccent,

        // The Row widget lines all of the children contained into a row
        child: Row(
          // Centers the icons in the navigation bar
          mainAxisAlignment: MainAxisAlignment.center,

          // Each TextButton calls the Navigator to navigate between the three main pages
          // The currently active page is given an onPressed value which is blank and are given a different color
          // This prevents the user from repeatedly pressing the button and causing performance issues
          // Pages which are not active use pushReplacementNamed to push the new page onto the navigator stack
          // The internal names for each page are defined by the developer and can be found in main.dart
          children: [
            TextButton(
              onPressed: () {
                Navigator.pushReplacementNamed(context, '/settings');
              },
              child: Icon(Icons.settings, size: 50, color: style.mainColor),
            ),
            TextButton(
              onPressed: () {
                Navigator.pushReplacementNamed(context, '/main');
              },
              child: Icon(Icons.house, size: 50, color: style.mainColor),
            ),
            TextButton(
              onPressed: () {},
              child: Icon(Icons.bar_chart, size: 50, color: style.selectedColor),
            ),
          ],
        ),
      ),// This trailing comma makes auto-formatting nicer for build methods.
    );
  }
}
