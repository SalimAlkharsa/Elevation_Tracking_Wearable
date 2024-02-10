import 'package:flutter/material.dart';
import 'package:application/style.dart' as style;
import 'package:google_sign_in/google_sign_in.dart';

class StartupPage extends StatelessWidget {
  const StartupPage({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text("Welcome"),
        backgroundColor: style.mainColor,
      ),
      body: Center(
          child: Column(
            mainAxisAlignment: MainAxisAlignment.center,
            children: [
              const Spacer(flex: 10),
              FloatingActionButton.extended(
                heroTag: "Login",
                onPressed: () {
                  Navigator.pushReplacementNamed(context, '/startup/login');
                },
                label: Text("Login", style: style.buttonTextStyle),
                backgroundColor: style.mainColor,
                foregroundColor: style.backgroundColor,
              ),
              const Spacer(flex: 1),
              FloatingActionButton.extended(
                heroTag: "Register",
                onPressed: () {
                  Navigator.pushReplacementNamed(context, '/startup/register');
                },
                label: Text("Create New Account", style: style.buttonTextStyle),
                backgroundColor: style.mainColor,
                foregroundColor: style.backgroundColor,
              ),
              const Spacer(flex: 10),
            ]
          )
      ),
    );
  }
}
