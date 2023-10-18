import 'package:flutter/cupertino.dart';
import 'package:flutter/material.dart';

class MainPage extends StatefulWidget {
  const MainPage({super.key});

  @override
  State<MainPage> createState() => _MainPageState();
}

class _MainPageState extends State<MainPage> {
  int _counter = 0;

  void _incrementCounter() {
    setState(() {
      // This call to setState tells the Flutter framework that something has
      // changed in this State, which causes it to rerun the build method below
      // so that the display can reflect the updated values. If we changed
      // _counter without calling setState(), then the build method would not be
      // called again, and so nothing would appear to happen.
      _counter++;
    });
  }

  void _resetCounter() {
    setState(() {
      _counter = 0;
    });
  }

  @override
  Widget build(BuildContext context) {
    // This method is rerun every time setState is called, for instance as done
    // by the _incrementCounter method above.
    //
    // The Flutter framework has been optimized to make rerunning build methods
    // fast, so that you can just rebuild anything that needs updating rather
    // than having to individually change instances of widgets.
    return Scaffold(
      appBar: AppBar(
        // Here we take the value from the MyHomePage object that was created by
        // the App.build method, and use it to set our appbar title.
        title: Text("MAIN PAGE"),
      ),
      body: Center(
        // Center is a layout widget. It takes a single child and positions it
        // in the middle of the parent.
        child: Column(
          // Column is also a layout widget. It takes a list of children and
          // arranges them vertically. By default, it sizes itself to fit its
          // children horizontally, and tries to be as tall as its parent.
          //
          // Invoke "debug painting" (press "p" in the console, choose the
          // "Toggle Debug Paint" action from the Flutter Inspector in Android
          // Studio, or the "Toggle Debug Paint" command in Visual Studio Code)
          // to see the wireframe for each widget.
          //
          // Column has various properties to control how it sizes itself and
          // how it positions its children. Here we use mainAxisAlignment to
          // center the children vertically; the main axis here is the vertical
          // axis because Columns are vertical (the cross axis would be
          // horizontal).
          mainAxisAlignment: MainAxisAlignment.spaceEvenly,
          children: <Widget>[
            const Text(
              'You have pushed the button this many times:',
            ),
            Text(
              '$_counter',
              style: Theme.of(context).textTheme.headlineMedium,
            ),
            Transform.scale(
              scale: 2.5,
              child: Row(
                children: [
                  Column(
                    children: [
                      CircularProgressIndicator(
                        value: _counter/10,
                        color: Colors.green,
                        strokeWidth: 4.0,
                      ),
                      Text("$_counter/10"),
                    ]
                  ),
                  Column(
                      children: [
                        CircularProgressIndicator(
                          value: (10-_counter)/10,
                          color: Colors.blue,
                          strokeWidth: 4.0,
                        ),
                        Text("$_counter/10"),
                      ]
                  ),
                ],
                mainAxisAlignment: MainAxisAlignment.center,
              ),
            ),
            TextButton(
                onPressed: () {
                  _incrementCounter();
      },
                child: Text("INCREMENT")),
            TextButton(
                onPressed: () {
                  _resetCounter();
                },
                child: Text("RESET")),
          ],
        ),
      ),
      bottomNavigationBar: BottomAppBar(
        child: Row(
          children: [
            TextButton(onPressed: () {
              Navigator.pushReplacementNamed(context,'/settings');
            },
                child: Icon(Icons.settings, size: 50)),
            TextButton(onPressed: () {},
                child: Icon(Icons.house, size: 50, color: Colors.black)),
            TextButton(onPressed: () {
              Navigator.pushReplacementNamed(context,'/metrics');
            },
                child: Icon(Icons.bar_chart, size: 50)),
          ],
          mainAxisAlignment: MainAxisAlignment.center,
        ),
        padding: EdgeInsets.all(5.0),

      ), // This trailing comma makes auto-formatting nicer for build methods.
    );
  }
}
