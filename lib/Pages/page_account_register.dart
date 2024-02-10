import 'package:flutter/material.dart';
import 'package:application/style.dart' as style;
import 'package:google_sign_in/google_sign_in.dart';

class AccountRegisterPage extends StatelessWidget {
  const AccountRegisterPage({Key? key}) : super(key: key);

  @override
  Widget build(BuildContext context) {
    return Scaffold(
      appBar: AppBar(
        title: const Text("Login Page"),
        backgroundColor: style.mainColor,
      ),
      body: Center(
        child: Column(
          children: [
            FloatingActionButton.extended(
              heroTag: "Main",
              onPressed: () {
                Navigator.pushReplacementNamed(context, '/main');
              },
              label: Text("Go to main...", style: style.buttonTextStyle),
              backgroundColor: style.mainColor,
              foregroundColor: style.backgroundColor,
            ),
          ]
        )
      ),
    );
  }
}
