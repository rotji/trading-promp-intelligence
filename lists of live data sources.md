# Lists of Live Data Sources

This file collects practical sources and tools for live macro, funding, order-flow, and execution data.

## How to use this file

1. Start with the data categories that are easiest for you to access.
2. Match your available tools to the required source types.
3. Use the lists as a checklist for building a live scan routine.
4. For each trade, verify macro, funding, and order-flow context before taking action.
5. Update this file over time as you add new feeds or platforms.

## 1. Macro data
Use these for real-time economic and policy context.

- Central bank websites / releases
  - Federal Reserve (Fed)
  - European Central Bank (ECB)
  - Bank of Japan (BOJ)
  - Bank of England (BOE)
  - Swiss National Bank (SNB)
  - Reserve Bank of Australia (RBA)
  - People’s Bank of China (PBOC)
- Economic calendars
  - ForexFactory
  - DailyFX
  - Investing.com
  - Econoday
  - Bloomberg Economic Calendar
- Public macro APIs
  - FRED API
  - TradingEconomics API
  - AlphaVantage
  - Quandl / Nasdaq Data Link
  - Twelve Data
- News providers
  - Reuters
  - Bloomberg
  - Financial Times
  - CNBC

## 2. Funding / liquidity data
Use these for repo, swap, dollar funding, credit, and liquidity stress.

- Fed / FRED
  - H.15 rates
  - SOFR
  - reverse repo / overnight repo
  - Fed balance sheet
- CME / ICE
  - Fed Funds futures
  - SOFR futures
  - Eurodollar curve
  - swap spreads
- BIS
  - FX swap turnover
  - global liquidity and funding reports
- Bank liquidity indicators
  - LIBOR/OIS spreads
  - Euribor-OIS spreads
  - CDS curves
  - Treasury repo rates
- Specialized data services
  - Bloomberg (swap spreads, repo, funding curves)
  - Refinitiv / LSEG
  - S&P Global Market Intelligence
  - IHS Markit

## 3. Order flow / execution verification
For real order-flow and liquidity confirmation.

- DOM / order-book tools
  - Bookmap
  - Jigsaw Trading
  - Sierra Chart
  - NinjaTrader
  - ATAS
  - Quantower
- Broker feeds with real volume/tick data
  - LMAX
  - FXCM
  - OANDA
  - Dukascopy
  - Saxo
  - Interactive Brokers (for futures/tick)
- Futures and options flow
  - COT reports (CFTC)
  - CME open interest
  - CME FX futures volume
  - options flow systems (e.g. SqueezeMetrics, OptionStrat, FlowAlgo)
- Tick-volume proxies
  - TradingView volume ticks
  - MT4/MT5 tick charts
  - broker-provided tick count
- Liquidity depth
  - Level 2 / DOM for futures or FX instruments
  - depth-of-market tools available in advanced platforms

## 3B. Institutional-grade real-time systems
For professional-level market infrastructure and data.

- Terminal platforms
  - Bloomberg Terminal (comprehensive macro, funding, positioning, news)
  - Refinitiv Eikon / Refinitiv Desktop (alternative to Bloomberg)
  - ICE Data (fixed income, derivatives, FX swap data)
  - CME Direct (direct futures and options data)
- Data aggregation platforms
  - CQG (charting, order flow, market depth)
  - dxFeed (real-time market data API and feeds)
  - Polygon (multi-asset real-time data API)
- Advanced order-flow and positioning feeds
  - Institutional options flow feeds (e.g., Unusual Whales, FlowAlgo, OptionStrat professional tier)
  - Prime broker feeds (proprietary bank-level positioning and funding data)
  - Swap dealer feeds (direct dealer positioning and inventory data)
  - Cross-bank liquidity feeds (aggregated interbank order-flow data)
- Specialized liquidity intelligence
  - BIS high-frequency FX swap and cross-border flow data
  - Dealer inventory and positioning services
  - Counterparty and contagion risk feeds

## 4. FX-specific structural flow / positioning
For FX equilibrium, relative strength, carry, and dealer context.

- BIS FX swap and funding reports
- CFTC FX futures positioning
- FX swap curves and cross-currency basis
- Carry trade indicators
  - yield differentials
  - swap points
  - funding cost curves
- Positioning data
  - COT
  - FX futures open interest
  - options delta/gamma exposure if available

## 5. Chart and footprint intelligence
For the chart footprints the prompt mentions.

- TradingView
- MT4 / MT5
- NinjaTrader
- Sierra Chart
- Bookmap / ATAS for footprint and liquidity sweep detection
- Volume profile / market-profile tools

## 6. Practical setup for pre-London routine
If you want a real “before London open” routine:
- Macro: check economic calendar + recent central bank signals
- Funding: inspect repo, swap spreads, dollar liquidity, SOFR
- Order flow: confirm via broker DOM or futures flow
- Chart: compare higher timeframes + current session structure
- Risk: verify news and volatility conditions before entry
- Governance: confirm the master execution authorization and survivability status from `module 0 All system rules and market classification framework` before committing
- Session readiness: during London/New York session and overlap, ensure session authorization and governance alignment are both confirmed before execution

## 7. Key point
The attached document is a workflow specification, not itself an automatic data source.

To make it work you need to connect it with:
- live macro feeds
- funding/liquidity feeds
- broker order-flow tools
- execution/chart platforms

## 8. Suggested real source categories

### Real-time macro sources
- Central bank releases
- Economic calendar feeds
- Real-time macro APIs
- Financial news services

### Real-time funding sources
- Repo and funding rate data
- Swap spreads and swap curves
- Dollar liquidity indicators
- CDS and credit spread data

### Real-time order flow sources
- DOM / order-book feeds
- Tick and volume feeds
- Futures / options positioning feeds
- Broker execution data

### Real-time structural data sources
- BIS liquidity / FX swap reports
- COT / futures positioning
- Options gamma / positioning systems
- Macro and funding overlays

## 9. Recommended steps to implement the prompt
1. Identify the tools you can access immediately.
2. Choose a chart platform with good session and volume tools.
3. Connect a macro calendar or API for news and policy data.
4. Add a funding data source for repo, swap, and dollar stress.
5. Add order-flow or tick-volume verification if available.
6. Use the list above as your daily scan checklist.

---

This file is intentionally designed to be stored separately from `PART TWO.MD` as a practical reference list.