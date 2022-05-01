#!/bin/bash
javac -d . tool/GenerateAst.java
java com.gavinlochtefeld.tool.GenerateAst lox/
