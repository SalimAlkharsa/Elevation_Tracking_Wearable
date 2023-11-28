import 'package:flutter/material.dart';
import 'package:application/style.dart' as style;
import 'package:google_sign_in/google_sign_in.dart';

class LoginPage extends StatelessWidget {
  const LoginPage({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text("Login Page"),
        backgroundColor: style.mainColor,
      ),
      body: Center(
        child: FloatingActionButton.extended(
          onPressed: () {
            Navigator.pushReplacementNamed(context, '/main');
          },
          icon: Icon(Icons.security, color: style.iconColor),
          label: const Text("Sign in with Google"),
          backgroundColor: style.mainColor,
          foregroundColor: style.backgroundColor,
        )
      ),
    );
  }
}
