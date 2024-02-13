import 'package:flutter/material.dart';
import 'package:application/style.dart' as style;
import 'package:application/connection.dart' as db;

class LoginPage extends StatefulWidget {
  const LoginPage({super.key});

  @override
  State<LoginPage> createState() => _LoginPageState();
}

class _LoginPageState extends State<LoginPage> {

  String username = "";
  String password = "";

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text("Login Page"),
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
                  Row(
                    mainAxisAlignment: MainAxisAlignment.center,
                    crossAxisAlignment: CrossAxisAlignment.center,
                    children: [
                      FloatingActionButton.extended(
                        heroTag: "Login",
                        onPressed: verifyLogin,
                        label: Text("Login", style: style.buttonTextStyle),
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

  Future<void> verifyLogin() async {
    List<List<dynamic>> results = await db.connection.query("SELECT password FROM login WHERE username='$username'");

    if (results.isEmpty) {
      errorNonexistentUser();
    } else if ((results[0][0] != password)) {
      errorWrongPassword();
    } else {
      loginSuccess();
    }
  }

  void loginSuccess() {
    Navigator.pushReplacementNamed(context, '/main');
  }

  void close() {
    Navigator.of(context).pop(context);
  }

  void errorNonexistentUser() => showDialog(
    context: context,
      builder: (context) => AlertDialog(
        backgroundColor: style.backgroundColor,
        title: Text("Error: User $username does not exist, please create an account", style: style.textStyle),
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

  void errorWrongPassword() => showDialog(
    context: context,
    builder: (context) => AlertDialog(
      backgroundColor: style.backgroundColor,
      title: Text("Error: Incorrect password", style: style.textStyle),
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

