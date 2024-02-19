import 'package:flutter/material.dart';
import 'package:application/style.dart' as style;
import 'package:application/connection.dart' as db;

class AccountRegisterPage extends StatefulWidget {
  const AccountRegisterPage({super.key});

  @override
  State<AccountRegisterPage> createState() => _AccountRegisterPageState();
}

class _AccountRegisterPageState extends State<AccountRegisterPage> {

  String username = "";
  String password = "";
  String first_name = "";
  String last_name = "";

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text("Create Account"),
        backgroundColor: style.mainColor,
      ),
      body: Center(
        child: Column(
          mainAxisAlignment: MainAxisAlignment.center,
          crossAxisAlignment: CrossAxisAlignment.center,
          children: [
            Form(
              child: Column(
                  children: [
                    Padding(
                      padding: const EdgeInsets.symmetric(horizontal: 30),
                      child: TextFormField(
                          keyboardType: TextInputType.text,
                          decoration: const InputDecoration(
                            labelText: 'Username',
                            hintText: 'Enter username',
                            prefixIcon: Icon(Icons.person),
                          ),
                          onChanged: (String value) {
                            setState(() {
                              username = value;
                            });
                          },
                          validator: (value) {
                            return value!.isEmpty ? 'Please enter a username' : null;
                          }
                      ),
                    ),
                    const SizedBox(height: 30),
                    Padding(
                      padding: const EdgeInsets.symmetric(horizontal: 30),
                      child: TextFormField(
                          keyboardType: TextInputType.text,
                          decoration: const InputDecoration(
                            labelText: 'Password',
                            hintText: 'Enter password',
                            prefixIcon: Icon(Icons.lock),
                          ),
                          onChanged: (String value) {
                            setState(() {
                              password = value;
                            });
                          },
                          validator: (value) {
                            return value!.isEmpty ? 'Please enter a username' : null;
                          }
                      ),
                    ),
                    const SizedBox(height: 30),
                    Padding(
                      padding: const EdgeInsets.symmetric(horizontal: 30),
                      child: TextFormField(
                          keyboardType: TextInputType.text,
                          decoration: const InputDecoration(
                            labelText: 'First Name',
                            hintText: 'Enter first name',
                            prefixIcon: Icon(Icons.text_fields),
                          ),
                          onChanged: (String value) {
                            setState(() {
                              first_name = value;
                            });
                          },
                          validator: (value) {
                            return value!.isEmpty ? 'Please enter a first name' : null;
                          }
                      ),
                    ),
                    const SizedBox(height: 30),
                    Padding(
                      padding: const EdgeInsets.symmetric(horizontal: 30),
                      child: TextFormField(
                          keyboardType: TextInputType.text,
                          decoration: const InputDecoration(
                            labelText: 'Last Name',
                            hintText: 'Enter last name',
                            prefixIcon: Icon(Icons.text_fields),
                          ),
                          onChanged: (String value) {
                            setState(() {
                              last_name = value;
                            });
                          },
                          validator: (value) {
                            return value!.isEmpty ? 'Please enter a last name' : null;
                          }
                      ),
                    ),
                    const SizedBox(height: 30),
                    Row(
                      mainAxisAlignment: MainAxisAlignment.center,
                      crossAxisAlignment: CrossAxisAlignment.center,
                      children: [
                        FloatingActionButton.extended(
                          heroTag: "Create Account",
                          onPressed: handleAccount,
                          label: Text("Create Account", style: style.buttonTextStyle),
                          backgroundColor: style.mainColor,
                          foregroundColor: style.backgroundColor,
                        ),
                        const SizedBox(width: 30),
                        FloatingActionButton.extended(
                          heroTag: "Back",
                          onPressed: () {
                            Navigator.pushReplacementNamed(context, '/');
                          },
                          label: Text("Back", style: style.buttonTextStyle),
                          backgroundColor: style.mainColor,
                          foregroundColor: style.backgroundColor,
                        ),
                      ]
                    ),
                  ]
              ),
            ),
          ],
        ),
      ),
    );
  }

  void handleAccount() {
    if (username.isEmpty) {
      errorEmpty("username");
    } else if (password.isEmpty) {
      errorEmpty("password");
    } else if (first_name.isEmpty) {
      errorEmpty("first name");
    } else if (last_name.isEmpty) {
      errorEmpty("last name");
    } else {
      verifyAccount();
    }
  }

  Future<void> verifyAccount() async {
    List<List<dynamic>> results = await db.connection.query("SELECT * FROM login WHERE username='$username'");

    if (results.isEmpty) {
      createUser();
      creationSuccess();
    } else {
      errorExistentUser();
    }
  }

  Future<void> createUser() async {
    await db.connection.query("INSERT INTO users (username, first_name, last_name, daily_floors) VALUES ('$username', '$first_name', '$last_name', 0)");
    await db.connection.query("INSERT INTO login (username, password) VALUES ('$username', '$password')");
  }

  void creationSuccess() {
    db.user = username;
    Navigator.pushReplacementNamed(context, '/main');
  }

  void close() {
    Navigator.of(context).pop(context);
  }

  void errorExistentUser() => showDialog(
    context: context,
    builder: (context) => AlertDialog(
      backgroundColor: style.backgroundColor,
      title: Text("Error: User $username already exists", style: style.textStyle),
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

  void errorEmpty(String type) => showDialog(
    context: context,
    builder: (context) => AlertDialog(
      backgroundColor: style.backgroundColor,
      title: Text("Error: Please enter a $type", style: style.textStyle),
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
}



