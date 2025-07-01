fun dbg(vararg args: Any?) { val line = Throwable().stackTrace[1].lineNumber; var i = 1; println("[$line] " + args.joinToString("  ") { if (it is Pair<*, *>) "${it.first}: ${format(it.second)}" else "_${i++}: ${format(it)}" }) }

fun format(x: Any?): String = when (x) {
    is Pair<*, *> -> "(${format(x.first)}, ${format(x.second)})"
    is Triple<*, *, *> -> "(${format(x.first)}, ${format(x.second)}, ${format(x.third)})"
    is Iterable<*> -> x.joinToString(", ", "{", "}") { format(it) }
    is Array<*> -> x.joinToString(", ", "{", "}") { format(it) }
    is Map<*, *> -> x.entries.joinToString(", ", "{", "}") { "${format(it.key)}: ${format(it.value)}" }
    else -> x.toString()
}
