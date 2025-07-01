fun dbg(vararg args: Any?) {
    val line = Throwable().stackTrace[1].lineNumber
    var autoIndex = 1
    val out = args.joinToString("  ") {
        when (it) {
            is Pair<*, *> -> "${it.first}: ${format(it.second)}"
            else -> "_${autoIndex++}: ${format(it)}"
        }
    }
    println("[$line] $out")
}

fun format(x: Any?): String = when (x) {
    is Pair<*, *> -> "(${format(x.first)}, ${format(x.second)})"
    is Triple<*, *, *> -> "(${format(x.first)}, ${format(x.second)}, ${format(x.third)})"
    is Iterable<*> -> x.joinToString(separator = ", ", prefix = "{", postfix = "}") { format(it) }
    is Array<*> -> x.joinToString(separator = ", ", prefix = "{", postfix = "}") { format(it) }
    is Map<*, *> -> x.entries.joinToString(separator = ", ", prefix = "{", postfix = "}") { "${format(it.key)}: ${format(it.value)}" }
    else -> x.toString()
}
